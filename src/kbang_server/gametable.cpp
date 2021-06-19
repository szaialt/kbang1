#include "gametable.h"
#include "common.h"
#include "player.h"
#include "util.h"
#include "gameeventmanager.h"
#include "gameexceptions.h"
#include "game.h"
#include "playingcard.h"
#include "cardfactory.h"
#include "checkdeckresulthandler.h"


GameTable::GameTable(Game* game):
        mp_game(game)
{
}


void GameTable::prepareGame(CardFactory* cardFactory) {
    generateCards(cardFactory);
    mp_game->gameEventManager().onGameSync(); 
    dealCards();
} 



QList<PlayingCard*> GameTable::playerDrawFromDeck(Player* player, int count, bool revealCards)
{
    QList<PlayingCard*> drawedCards;
    for(int i = 0; i < count; ++i)
    {
        PlayingCard* card = popCardFromDeck();
        Q_ASSERT(!card->isVirtual());
        player->appendCardToHand(card);
        card->setOwner(player);
        card->setPocket(POCKET_HAND);
        drawedCards.append(card);
    }
    mp_game->gameEventManager().onPlayerDrawFromDeck(player, drawedCards, revealCards);
    mp_game->gameEventManager().onPlayerUpdated(player);
    return drawedCards;
}

void GameTable::playerDrawFromGraveyard(Player* player)
{
    if (m_graveyard.size() == 0)
        throw BadGameStateException();
    PlayingCard* card = m_graveyard.takeLast();
    Q_ASSERT(!card->isVirtual());
    player->appendCardToHand(card);
    card->setOwner(player);
    card->setPocket(POCKET_HAND);
    PlayingCard* nextCard = m_graveyard.isEmpty() ? 0 : m_graveyard.first();
    mp_game->gameEventManager().onPlayerDrawFromGraveyard(player, card, nextCard);
    mp_game->gameEventManager().onPlayerUpdated(player);

}

PlayingCard* GameTable::playerDrawDynamiteFromGraveyard(Player* player)
{
    if (m_graveyard.size() == 0)
        throw BadGameStateException();
    foreach(PlayingCard* card, m_graveyard){
        if (card->type() == CARD_DYNAMITE){
        Q_ASSERT(!card->isVirtual());
           m_graveyard.removeAll(card);
           player->appendCardToHand(card);
           card->setOwner(player);
           card->setPocket(POCKET_HAND);
           PlayingCard* nextCard = m_graveyard.isEmpty() ? 0 : m_graveyard.first();
           mp_game->gameEventManager().onPlayerDrawFromGraveyard(player, card, nextCard);
           mp_game->gameEventManager().onPlayerUpdated(player);
           return card;
        }
    }
    throw BadGameStateException();

}

void GameTable::playerDiscardCard(PlayingCard* card)
{
    //It sends a sign to Freddy Street-Sweeper, so he can use his ability
    //It can bee that he needs a new GAMEACTION
    Q_ASSERT(!card->isVirtual());
    if (card == 0) return;
    Player*     owner  = card->owner();
    PocketType  pocket = card->pocket(); 
 
    Q_ASSERT((card->pocket() == POCKET_HAND) || (card->pocket() == POCKET_TABLE));
    moveCardToGraveyard(card);

    mp_game->gameEventManager().onPlayerDiscardCard(owner, card, pocket);
    owner->checkEmptyHand();
    mp_game->gameEventManager().onPlayerUpdated(owner); 

}


void GameTable::playerPlayCard(PlayingCard* card)
{
    if (card->isVirtual())
        card = card->master();
    if (card == 0) return;
    Q_ASSERT(card->pocket() == POCKET_HAND || card->pocket() == POCKET_TABLE);
    PocketType pocket = card->pocket();
    Player* owner = card->owner();
    moveCardToGraveyard(card);
    mp_game->gameEventManager().onPlayerPlayCard(owner, card, pocket);
    owner->checkEmptyHand();
    mp_game->gameEventManager().onPlayerUpdated(owner); 

}

void GameTable::playerPlayCard(PlayingCard* card, Player* targetPlayer)
{
    if (card->isVirtual())
        card = card->master();
    if (card == 0) return;
    Q_ASSERT(card->pocket() == POCKET_HAND || card->pocket() == POCKET_TABLE);
    PocketType pocket = card->pocket();
    Player* owner = card->owner();
    moveCardToGraveyard(card);
    mp_game->gameEventManager().onPlayerPlayCard(owner, card, targetPlayer, pocket);
    owner->checkEmptyHand();
    mp_game->gameEventManager().onPlayerUpdated(owner);

} 

void GameTable::playerPlayCard(PlayingCard* card, PlayingCard* targetCard)
{
    if (card->isVirtual())
        card = card->master();
    if (card == 0) return;
    Q_ASSERT(card->pocket() == POCKET_HAND || card->pocket() == POCKET_TABLE);
    Q_ASSERT(!targetCard->isVirtual());
    PocketType pocket1 = card->pocket();
    PocketType pocket2 = targetCard->pocket();
    Player* owner = card->owner();
    moveCardToGraveyard(card);
    mp_game->gameEventManager().onPlayerPlayCard(owner, card, targetCard, pocket1, pocket2);
    owner->checkEmptyHand();
    mp_game->gameEventManager().onPlayerUpdated(owner);

    
}

void GameTable::playerPlayCard(PlayingCard* card, PlayingCard* targetCard, Player* targetPlayer)
{
    if (card->isVirtual())
        card = card->master();
    if (card == 0) return;
    Q_ASSERT(card->pocket() == POCKET_HAND || card->pocket() == POCKET_TABLE);
    Q_ASSERT(!targetCard->isVirtual());
    PocketType pocket1 = card->pocket();
    PocketType pocket2 = targetCard->pocket();
    Player* owner = card->owner();
    moveCardToGraveyard(card);
    mp_game->gameEventManager().onPlayerPlayCard(owner, card, targetCard, targetPlayer, pocket1, pocket2);
    owner->checkEmptyHand();
    mp_game->gameEventManager().onPlayerUpdated(owner);
}

void GameTable::playerPlayCardOnTable(PlayingCard* card, Player* targetPlayer)
{
    if (card->isVirtual())
        card = qobject_cast<PlayingCard*>(card->master());
    Q_ASSERT(card != 0);
    Q_ASSERT(card->pocket() == POCKET_HAND);
    Player* owner = card->owner();

    if (targetPlayer == 0)
        targetPlayer = owner;

    owner->removeCardFromHand(card);

    targetPlayer->appendCardToTable(card);
    card->setOwner(targetPlayer);
    card->setPocket(POCKET_TABLE);
    card->registerPlayer(targetPlayer);

    mp_game->gameEventManager().onPlayerPlayCardOnTable(owner, card, targetPlayer);
    owner->checkEmptyHand();
    mp_game->gameEventManager().onPlayerUpdated(owner);

}

void GameTable::passTableCard(PlayingCard* card, Player* targetPlayer)
{
    Q_ASSERT(card->pocket() == POCKET_TABLE);
    if (card->isVirtual())
        card = qobject_cast<PlayingCard*>(card->master());
    Q_ASSERT(card != 0);
    Player* owner = card->owner();

    owner->removeCardFromTable(card);
    card->unregisterPlayer(owner);

    targetPlayer->appendCardToTable(card);
    card->setOwner(targetPlayer);
    card->setPocket(POCKET_TABLE);
    card->registerPlayer(targetPlayer);
    mp_game->gameEventManager().onPassTableCard(owner, card, targetPlayer);
    mp_game->gameEventManager().onPlayerUpdated(owner);

}

void GameTable::playerPass(Player* player)
{
    mp_game->gameEventManager().onPlayerPass(player);
}

void GameTable::playerRespondWithCard(PlayingCard* card)
{
    if (card->isVirtual())
        card = card->master();
    Q_ASSERT((card->pocket() == POCKET_HAND) || (card->pocket() == POCKET_TABLE));
    if (card == 0) {
        return;
    } 
    Player* owner = card->owner();
    if (owner == 0) {
        return;
    } 
    moveCardToGraveyard(card);
    mp_game->gameEventManager().onPlayerRespondWithCard(owner, card);
    owner->checkEmptyHand();
    mp_game->gameEventManager().onPlayerUpdated(owner);

}

void GameTable::drawIntoSelection(int count, Player* selectionOwner)
{
    Q_ASSERT(m_selection.isEmpty());
    QList<const PlayingCard*> drawedCards;
    for(int i = 0; i < count; ++i)
    {
        PlayingCard* card = popCardFromDeck();
        Q_ASSERT(!card->isVirtual());
        m_selection.append(card);
        card->setOwner(selectionOwner);
        card->setPocket(POCKET_SELECTION);
        drawedCards.append(card);
    }
    if (selectionOwner == 0){
        mp_game->gameEventManager().onDrawIntoSelection(drawedCards);
    }
    else {
        mp_game->gameEventManager().onDrawIntoSelection(selectionOwner, drawedCards);
    }
}

void GameTable::drawIntoSelection(int count)
{
    Q_ASSERT(m_selection.isEmpty());
    QList<const PlayingCard*> drawedCards;
    for(int i = 0; i < count; ++i)
    {
        PlayingCard* card = popCardFromDeck();
        Q_ASSERT(!card->isVirtual());
        m_selection.append(card);
        card->setPocket(POCKET_SELECTION);
        drawedCards.append(card);
    }
    mp_game->gameEventManager().onDrawIntoSelection(drawedCards);
}

void GameTable::drawHandIntoSelection(Player* selectionOwner)
{
    Q_ASSERT(selectionOwner != 0);
    QList<const PlayingCard*> drawedCards;
    QList<PlayingCard*> hand = selectionOwner->hand();
    foreach (PlayingCard* card, hand)
    {
        Q_ASSERT(!card->isVirtual());
        selectionOwner->removeCardFromHand(card);
        m_selection.append(card);
        card->setOwner(selectionOwner);
        card->setPocket(POCKET_SELECTION);
        drawedCards.append(card);
    }
    
    mp_game->gameEventManager().onDrawIntoSelection(selectionOwner, drawedCards);
    
}

void GameTable::drawGraveyardIntoSelection(Player* selectionOwner)
{
    Q_ASSERT(m_selection.isEmpty());
    QList<const PlayingCard*> drawedCards;
    if (m_graveyard.size() == 0)
        throw BadGameStateException();
    foreach (PlayingCard* card, m_graveyard)
    {
        PlayingCard* card2 = m_graveyard.takeLast();
        Q_ASSERT(!card2->isVirtual());
        m_selection.append(card2);
        card2->setOwner(selectionOwner);
        card2->setPocket(POCKET_SELECTION);
        drawedCards.append(card2);
    }
    if (selectionOwner == 0){
        mp_game->gameEventManager().onDrawIntoSelection(drawedCards);
    }
    else {
        mp_game->gameEventManager().onDrawIntoSelection(selectionOwner, drawedCards);
    }
}

void GameTable::drawGraveyardIntoSelection(int count)
{
    Q_ASSERT(m_selection.isEmpty());
    QList<const PlayingCard*> drawedCards;
    if (m_graveyard.size() == 0)
        throw BadGameStateException();
    int i = 0;
    foreach (PlayingCard* card, m_graveyard)
    {
        if (i < count){
            PlayingCard* card2 = m_graveyard.takeLast();
            Q_ASSERT(!card2->isVirtual());
            card2->setOwner(0);
            card2->setPocket(POCKET_SELECTION);
            m_selection.append(card2);
            drawedCards.append(card2);
            i++;
        }
    }
    mp_game->gameEventManager().onDrawIntoSelection(drawedCards);
}

void GameTable::playerPickFromSelection(Player* player, PlayingCard* card)
{
    try {
        if (card->isVirtual())
            card = card->master();
        bool revealCard = (card->owner() != player);
        m_selection.removeAll(card);
        player->appendCardToHand(card);
        card->setOwner(player);
        card->setPocket(POCKET_HAND);
        mp_game->gameEventManager().onPlayerPickFromSelection(player, card, revealCard);
    }
    catch(GameException& e) {
        qDebug() << QString("void GameTable::playerPickFromSelection: GameException");
        e.debug();
    } 
}

void GameTable::undrawFromSelection(PlayingCard* card)
{
    Q_ASSERT(m_selection.contains(card));
    Player* owner = card->owner();
    m_selection.removeAll(card);
    putCardToDeck(card);
    card->setOwner(0);
    card->setPocket(POCKET_DECK);
    mp_game->gameEventManager().onUndrawFromSelection(card, owner);
}

void GameTable::undrawCard(PlayingCard* card)
{
    Q_ASSERT(card->pocket() == POCKET_HAND);
    Player* owner = card->owner();
    owner->removeCardFromHand(card);
    putCardToDeck(card);
    card->setOwner(0);
    card->setPocket(POCKET_DECK);
    owner->checkEmptyHand();
    mp_game->gameEventManager().onPlayerUpdated(owner);
}

/*
void GameTable::playerCheckDeck(Player* player, PlayingCard* causedBy, bool (*checkFunc)(PlayingCard*),
                                CheckDeckResultHandler* resultHandler)
{
    if (causedBy->isVirtual())
        causedBy = 0;
    PlayingCard* checkedCard = popCardFromDeck();
    Q_ASSERT(!checkedCard->isVirtual());
    putCardToGraveyard(checkedCard);
    checkedCard->setOwner(0);
    checkedCard->setPocket(POCKET_GRAVEYARD);
    bool checkResult = (*checkFunc)(checkedCard);
    mp_game->gameEventManager().onPlayerCheckDeck(player, checkedCard, causedBy, checkResult);
    resultHandler->checkResult(checkResult);
}
*/

PlayingCard* GameTable::checkDeck()
{
    PlayingCard* checkedCard = popCardFromDeck();
    Q_ASSERT(!checkedCard->isVirtual());
    putCardToGraveyard(checkedCard);
    checkedCard->setOwner(0);
    checkedCard->setPocket(POCKET_GRAVEYARD);
    mp_game->gameEventManager().onCancelCard(0, POCKET_DECK, checkedCard, 0);
    return checkedCard;
}

void GameTable::playerStealCard(Player* player, PlayingCard* card)
{
    Q_ASSERT(!card->isVirtual());
    PocketType pocket = card->pocket();
    Player*    owner  = card->owner();
    switch(pocket) {
    case POCKET_HAND:
        owner->removeCardFromHand(card);
        break;
    case POCKET_TABLE:
        owner->removeCardFromTable(card);
        card->unregisterPlayer(owner);
        break;
    default:
        NOT_REACHED();
    }
    player->appendCardToHand(card);
    card->setOwner(player);
    card->setPocket(POCKET_HAND);

    mp_game->gameEventManager().onPlayerStealCard(player, owner, pocket, card);
    owner->checkEmptyHand();
    mp_game->gameEventManager().onPlayerUpdated(owner);
    mp_game->gameEventManager().onPlayerUpdated(player);
}


void GameTable::cancelCard(PlayingCard* card, Player* player)
{
    Q_ASSERT(!card->isVirtual());
    PocketType pocket = card->pocket();
    Player*    owner  = card->owner();

    moveCardToGraveyard(card); 

    mp_game->gameEventManager().onCancelCard(owner, pocket, card, player);
    if (owner != 0 && pocket == POCKET_HAND){
        //if (mp_game->gameCycle().gamePlayState() != GAMEPLAYSTATE_DISCARD)
            owner->checkEmptyHand();
    }
    //mp_game->gameEventManager().onPlayerUpdated(owner);
}

void GameTable::cancelSelection()
{
    while(!m_selection.isEmpty()) {
        cancelCard(m_selection.first());
    }
}

PlayingCard* GameTable::playerDrawFromBank(Player* player){
    PlayingCard* drawedCard;
    if (player->bank().isEmpty()) throw BadUsageException();
    PlayingCard* card = player->bank().takeFirst();
    Q_ASSERT(!card->isVirtual());
    player->appendCardToHand(card);
    card->setOwner(player);
    card->setPocket(POCKET_HAND);    
    mp_game->gameEventManager().onPlayerDrawFromBank(player, card, false);
    mp_game->gameEventManager().onPlayerUpdated(player);
    return card;
}

void GameTable::playerPlayCardOnBank(PlayingCard* card){
if (card->isVirtual())
        card = qobject_cast<PlayingCard*>(card->master());
    Q_ASSERT(card != 0);
    Q_ASSERT(card->pocket() == POCKET_HAND);
    Player* owner = card->owner();

    owner->removeCardFromHand(card);

    owner->appendCardToBank(card);
    card->setOwner(owner);
    card->setPocket(POCKET_BANK);

    mp_game->gameEventManager().onPlayerPlayCardOnBank(owner, card);
    owner->checkEmptyHand();
    mp_game->gameEventManager().onPlayerUpdated(owner);
}

bool GameTable::isEmptyGraveyard() const
{
    return m_graveyard.isEmpty();
}

PlayingCard* GameTable::graveyardTop() const
{
    if (m_graveyard.isEmpty()) {
        return 0;
    } 
    return m_graveyard.last();
}

void GameTable::generateCards(CardFactory* cardFactory)
{
    m_cards = cardFactory->generateCards(mp_game);
    m_deck << m_cards.values();
    shuffleDeck();
}

void GameTable::shuffleDeck()
{
    shuffleList(m_deck);
}


void GameTable::dealCards()
{
    int cardCount = 0, players = 0;
    do {
        players = 0;
        foreach(Player* p, mp_game->playerList())
        {
            if (p->initialCardCount() > cardCount)
            {
                playerDrawFromDeck(p);
                players++;
            }
        }
        cardCount++;
    } while(players != 0);
}

void GameTable::regenerateDeck()
{
    Q_ASSERT(m_deck.isEmpty());
    Q_ASSERT(!m_graveyard.isEmpty());
    m_deck << m_graveyard;
    m_graveyard.clear();
    m_graveyard << m_deck.takeLast();
    shuffleDeck();
    foreach(Player* p, mp_game->playerList())
    {
        if (p->characterType() == CHARACTER_TIM_CROUPIER){
            foreach(Player* p1, mp_game->playerList()){
                PlayingCard* card = p1->getRandomCardFromHand();
                playerStealCard(p, card);
            }
        }
    }
    mp_game->gameEventManager().onDeckRegenerate();
}

void GameTable::moveCardToGraveyard(PlayingCard* card)
{
    Player* owner = card->owner();
    switch(card->pocket()) {
    case POCKET_HAND:
        owner->removeCardFromHand(card);
        break;
    case POCKET_TABLE:
        owner->removeCardFromTable(card);
        card->unregisterPlayer(owner);
        break;
    case POCKET_SELECTION:
        m_selection.removeAll(card);
        break;
    case POCKET_DECK:
        if (!m_deck.isEmpty() && m_deck.first() == card) {
            popCardFromDeck();
        }
        break;
    case POCKET_GRAVEYARD:
    default:
        qDebug() << pocketTypeToString(card->pocket());
        NOT_REACHED();
    }
    putCardToGraveyard(card);
    card->setOwner(0);
    card->setPocket(POCKET_GRAVEYARD);
    //mp_game->gameEventManager().onPlayerUpdated(owner);

}


PlayingCard* GameTable::popCardFromDeck()
{
    if (m_deck.isEmpty()) regenerateDeck();
    return m_deck.takeFirst();
}

void GameTable::putCardToDeck(PlayingCard* card)
{
    m_deck.push_front(card);
}

void GameTable::putCardToGraveyard(PlayingCard* card)
{
    m_graveyard.push_back(card);
}

PlayingCard* GameTable::card(int cardId) {
     return (m_cards.contains(cardId)) ? m_cards[cardId] : 0;
  }

QList<PlayingCard*> GameTable::selection() { 
        return m_selection; 
}
    
    
