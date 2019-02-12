#include "gameactionmanager.h"
#include "game.h"
#include "playerwidget.h"
#include "serverconnection.h"
#include "cardwidget.h"
#include "cardzoomwidget.h"

using namespace client;

GameActionManager::GameActionManager(Game* game):
        m_state(STATE_MAIN),
        mp_game(game),
        mp_activeCard(0)
{
}



bool GameActionManager::isClickable(CardWidget*)
{
    return 1;
}

bool GameActionManager::onCardClicked(CardWidget* cardWidget)
{
    if (!mp_game->isAbleToRequest())
        return 0;

    switch(m_state) {
    case STATE_DISCARD:
        if (cardWidget->pocketType() != POCKET_HAND ||
            cardWidget->ownerId()    != mp_game->playerId())
            return 0;
        mp_game->serverConnection()->discardCard(cardWidget->cardData().id);
        return 1;

    case STATE_SELECT_PLAYER:
        unsetActiveCard();
        return 1;

    case STATE_SELECT_CARDS:
        Q_ASSERT(mp_activeCard != 0);
        if (cardWidget == mp_activeCard) {
            unsetActiveCard();
            return 1;
        }
        if (m_cardSelection.contains(cardWidget)) {
            removeFromSelection(cardWidget);
            return 1;
        }

        addToSelection(cardWidget);
        if (m_cardSelection.size() == m_selectionSize) {
            if (mp_activeCard->type() == Card::Character) {
                useAbilityWithCards();
            } else {
                playWithCards();
            }
            unsetActiveCard();
        }
        return 1;

    case STATE_MAIN:
        if (cardWidget->type() == Card::Character &&
            cardWidget->ownerId() == mp_game->playerId()) {
            onCharacterClicked(cardWidget);
            return 1;
        }

        if (cardWidget->pocketType() == POCKET_DECK) {
            mp_game->serverConnection()->drawCard();
            return 1;
        }

        if (cardWidget->cardData().id == 0)
            return 0;

        if (mp_game->gamePlayState() == GAMEPLAYSTATE_RESPONSE) {
            mp_game->serverConnection()->playCard(cardWidget->cardData().id);
            return 1;
        } 

        if (isCombined(cardWidget))
            onMainCardClicked(cardWidget);
        else
            mp_game->serverConnection()->playCard(cardWidget->cardData().id);
        return 1;
    }

    return 1;
} 

bool GameActionManager::isCombined(CardWidget* cardWidget){
    if ((cardWidget->pocketType() == POCKET_TABLE) && (cardWidget->cardData().type == CARD_MEDI_GUN)) return true;
    if ((cardWidget->pocketType() == POCKET_TABLE) && (cardWidget->cardData().type == CARD_PERSUASION)) return true;
    if (cardWidget->pocketType() == POCKET_HAND) return true;
    if (cardWidget->cardData().type == CARD_JAIL) return false;
    if (cardWidget->cardData().type == CARD_DYNAMITE) return false;
    if (cardWidget->cardData().type == CARD_TELEPORT) return false;
    if (cardWidget->cardData().type == CARD_SUN_GLARE) return false;
    return ((((cardWidget->pocketType() == POCKET_TABLE) && ((cardWidget->cardData().isAct)))) 
            && (cardWidget->ownerId() == mp_game->playerId()));
}

void GameActionManager::onCardRightClicked(CardWidget* cardWidget)
{
    new CardZoomWidget(mp_game, cardWidget);
}

void GameActionManager::onPlayerClicked(PlayerWidget* playerWidget)
{
    if (!mp_game->isAbleToRequest() || m_state != STATE_SELECT_PLAYER ||
        playerWidget->id() == 0     || mp_activeCard == 0)
        return;

    if (mp_activeCard->type() == Card::Character) {
        mp_game->serverConnection()->useAbility(playerWidget->id());
    } else {
        mp_game->serverConnection()->playCardWithPlayer(mp_activeCard->cardData().id, playerWidget->id());
    }
    unsetActiveCard();
}

void GameActionManager::onEndTurnClicked()
{
    unsetActiveCard();
    mp_game->serverConnection()->endTurn();
}

void GameActionManager::onPassClicked()
{
    unsetActiveCard();
    mp_game->serverConnection()->pass();
}

void GameActionManager::setDiscardMode(bool inDiscardMode)
{
    unsetActiveCard();
    m_state = inDiscardMode ? STATE_DISCARD : STATE_MAIN;
}

void GameActionManager::onMainCardClicked(CardWidget* cardWidget)
{
    switch (cardWidget->cardData().type) {
        //Choose target player
        case CARD_BANG:
        case CARD_DUEL:
        case CARD_JAIL:
        case CARD_DIRECT_HIT:
        case CARD_HEALING_BANG:
        case CARD_GUITAR:
        case CARD_TELEPORT:
        case CARD_JARATE:
        case CARD_SUN_GLARE:
                selectPlayer(cardWidget);
                break; 
        //Play it to table or choose two cards (blue)
        case CARD_PERSUASION:
        case CARD_MEDI_GUN:
            if (cardWidget->cardData().pocket == POCKET_TABLE){
                 selectCards(cardWidget, 2);
             }
             else if (cardWidget->cardData().pocket == POCKET_HAND){
                mp_game->serverConnection()->playCard(cardWidget->cardData().id);
             }
             break;
        //Choose a card
        case CARD_PANIC:
        case CARD_CATBALOU:
        case CARD_SUPPLY_CRATE:
                selectCards(cardWidget, 1);
                break;
        case CARD_ARSON:
                selectCards(cardWidget, 2);
                break;
        default:
            if (cardWidget->cardData().type == CARD_MISSED &&
                mp_game->character() == CHARACTER_CALAMITY_JANET) {
                selectPlayer(cardWidget);
                break;
            }
            mp_game->serverConnection()->playCard(cardWidget->cardData().id);
            break;
    }
}

void GameActionManager::onCharacterClicked(CardWidget* cardWidget)
{
    switch(mp_game->character()) {
    case CHARACTER_JESSE_JONES:
        selectPlayer(cardWidget);
        break;
//         selectCards(cardWidget, 1);
//         break;
    case CHARACTER_SID_KETCHUM:
    case CHARACTER_ENGINEER:
    case CHARACTER_HEAVY:
    case CHARACTER_MEDIC:
    case CHARACTER_DJANGO:
    case CHARACTER_JOHN_FORD:
    case CHARACTER_PAT_GARRETT:
    case CHARACTER_VIENNA:
    case CHARACTER_WYATT_EARP:
        selectCards(cardWidget, 2);
        break;
    case CHARACTER_PYRO:
        selectCards(cardWidget, 3);
        break;
    default:
        mp_game->serverConnection()->useAbility();
        break;
    }
}

void GameActionManager::selectPlayer(CardWidget* activeCard)
{
    Q_ASSERT(mp_activeCard == 0);
    Q_ASSERT(m_state == STATE_MAIN);
    mp_activeCard = activeCard;
    m_state = STATE_SELECT_PLAYER;
    mp_activeCard->setHighlight(1);
}

void GameActionManager::selectCards(CardWidget* activeCard, int cardCount)
{
    Q_ASSERT(mp_activeCard == 0);
    Q_ASSERT(m_state == STATE_MAIN);
    mp_activeCard = activeCard;
    m_state = STATE_SELECT_CARDS;
    m_cardSelection.clear();
    m_selectionSize = cardCount;
    mp_activeCard->setHighlight(1);
}

void GameActionManager::selectCardsAndPlayer(CardWidget* activeCard, int cardCount)
{
   selectCards(activeCard, cardCount);
   selectPlayer(activeCard);
}

void GameActionManager::unsetActiveCard()
{
    if (m_state == STATE_SELECT_CARDS) {
        foreach (CardWidget* c, m_cardSelection)
            removeFromSelection(c);
    }
    if (mp_activeCard != 0) {
        mp_activeCard->setHighlight(0);
        mp_activeCard = 0;
    }
    m_state = STATE_MAIN;
}


void GameActionManager::addToSelection(CardWidget* card)
{
    m_cardSelection.append(card);
    if (m_cardSelection.size() != m_selectionSize)
        card->setHighlight(1);
}

void GameActionManager::removeFromSelection(CardWidget* card)
{
    m_cardSelection.removeAll(card);
    card->setHighlight(0);
}

void GameActionManager::useAbilityWithCards()
{
    QList<int> cards;
    QList<int> ids;
    foreach (CardWidget* card, m_cardSelection)
        cards.append(card->cardData().id);
     switch(mp_game->character()) {
         case CHARACTER_SPY: {
             CardWidget* card = m_cardSelection.at(0);   
             int id = card->ownerId();
             int cardId = card->cardData().id;
             qDebug() << "Client: cardId" << cardId;
             mp_game->serverConnection()->useAbility(id);
             break;
         }
         case CHARACTER_ENGINEER:
         case CHARACTER_MEDIC:
         case CHARACTER_JOHN_FORD:
         case CHARACTER_PAT_GARRETT:
         case CHARACTER_VIENNA:
         case CHARACTER_WYATT_EARP: {
             CardWidget* card = m_cardSelection.at(0); 
             int cardId = card->cardData().id;
             qDebug() << "Client: cardId" << cardId;
             CardWidget* card2 = m_cardSelection.at(1); 
             cards.append(card->cardData().id);
             int id = card2->ownerId();
             mp_game->serverConnection()->useAbility(cards, id);
             break;
         }
         default: {
             mp_game->serverConnection()->useAbility(cards);
         }
     }
}

void GameActionManager::playWithCards()
{
    if (m_cardSelection.size() == 1) {
        CardWidget* card = m_cardSelection[0];        
        if ((mp_activeCard->pocketType() == POCKET_HAND) && (needsAnotherCardToUse(mp_activeCard->cardData()))){
            //Needs to be played from hand with an another card
            mp_game->serverConnection()->playCardWithCard(mp_activeCard->cardData().id, card->cardData().id);
            
        }
        else if ((card->pocketType() == POCKET_TABLE) && (needsTarget(mp_activeCard->cardData()) && (mp_activeCard->cardData().isAct))) {
             //Needs to be played from table with an another card
            mp_game->serverConnection()->playCardWithCard(mp_activeCard->cardData().id, card->cardData().id);
        }
        else if ((card->pocketType() == POCKET_HAND) && (needsTarget(mp_activeCard->cardData())) && (mp_activeCard->cardData().isAct)) {
            //Played from hand, needs a player as a target
            mp_game->serverConnection()->playCardWithPlayer(mp_activeCard->cardData().id, card->ownerId());
            
        }
        else if (card->pocketType() == POCKET_HAND)  {
            //Played from hand, needs a player as a target
            mp_game->serverConnection()->playCardWithPlayer(mp_activeCard->cardData().id, card->ownerId());
        } else {
            //For brawl, it throws out random cards from hand
            mp_game->serverConnection()->playCardWithCard(mp_activeCard->cardData().id, card->cardData().id);
        }
    } 
    else if (m_cardSelection.size() == 2) {
        if (mp_activeCard->cardData().type == CARD_ARSON){
            //Cards that need two target players
            CardWidget* card = m_cardSelection[0];
            CardWidget* card2 = m_cardSelection[1];
            int targetId1 = card->ownerId();
            int targetId2 = card2->ownerId();
            QList<int> playerIds;
            playerIds.push_back(targetId1);
            playerIds.push_back(targetId2);
            mp_game->serverConnection()->playCardWithPlayers(mp_activeCard->cardData().id, playerIds);
        }
        else {
        //Cards that need both an another card and a target player
            CardWidget* card = m_cardSelection[0];
            CardWidget* card2 = m_cardSelection[1];
            mp_game->serverConnection()->playCardWithCardAndPlayer(mp_activeCard->cardData().id, card->cardData().id, card2->ownerId());
        }
    }
    else {
        NOT_REACHED();
    }
}


void GameActionManager::debug(const QString& msg)
{
    qDebug(qPrintable(QString("[Click]         %1").arg(msg)));
}

bool GameActionManager::needsTarget(const CardData card){
    switch(card.type) {
    case CARD_BANG:
    case CARD_DUEL:
    case CARD_JAIL:
    case CARD_PANIC:
    case CARD_CATBALOU:
    case CARD_DIRECT_HIT:
    case CARD_HEALING_BANG:
    case CARD_GUITAR:
    case CARD_TELEPORT:
    case CARD_JARATE:
    case CARD_SUN_GLARE:
        return true;
    default:
        return false;
    }
}

bool GameActionManager::needsAnotherCardToUse(const CardData card){
    switch(card.type) {
    case CARD_SUPPLY_CRATE:
        return true;
    default:
        return false;
    }
}
