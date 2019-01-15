#include "cardteleport.h"

#include "gameexceptions.h"
#include "player.h"
#include "gametable.h"
#include "gamecycle.h"

CardTeleport::CardTeleport(Game *game, int id, CardSuit suit, CardRank rank, int PredrawCheck):
        PlayingCard(game, id, CARD_TELEPORT, suit, rank)
{
    m_PredrawCheck = PredrawCheck;
}

CardTeleport::~CardTeleport()
{
}

CardColor CardTeleport::color() const{
    return COLOR_BLUE;
}

void CardTeleport::play()
{
    
    gameCycle()->assertDraw();
    assertOnTable();
    owner()->predrawCheck(m_PredrawCheck);
    gameCycle()->checkDeck(owner(), this, *CardTeleport::check, this);
}


void CardTeleport::play(Player* targetPlayer)
{
    gameCycle()->assertTurn();
    assertInHand();

    if (targetPlayer->hasIdenticalCardOnTable(this)) {
        throw TwoSameOnTableException();
    }
    gameTable()->playerPlayCardOnTable(this, targetPlayer);
}

void CardTeleport::checkResult(bool result)
{       
    qDebug() << "CardTeleport: check is " << result;
    Player* owner1 = owner();
    gameTable()->playerDiscardCard(this);
    if (result) {
        gameCycle()->setDuplicateTurn(true);
        owner1->onBangPlayed(false);
    }
}


void CardTeleport::registerPlayer(Player* player)
{
    player->registerPredrawCheck(m_PredrawCheck);
}

void CardTeleport::unregisterPlayer(Player* player)
{
    player->unregisterPredrawCheck(m_PredrawCheck);
}

bool CardTeleport::check(PlayingCard* card)
{
    return (card->suit() == SUIT_HEARTS);

}
