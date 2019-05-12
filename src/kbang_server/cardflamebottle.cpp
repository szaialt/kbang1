#include "cardflamebottle.h"
#include "gamecycle.h"
#include "gameexceptions.h"
#include "gametable.h"
#include "game.h"
#include "player.h"

CardFlameBottle::CardFlameBottle(Game *game, int id, CardSuit suit, CardRank rank):
        PlayingCard(game, id, CARD_INFLAMMATORY_BOTTLE, suit, rank)
{

}

CardColor CardFlameBottle::color() const {
    return COLOR_BLUE;
}

void CardFlameBottle::play()
{
    assertOnTable();
    gameTable()->playerDiscardCard(this);
    gameCycle()->skipPlayersTurn();
}    

void CardFlameBottle::play(Player* targetPlayer)
{
    gameCycle()->assertTurn();
    assertInHand();
    if (targetPlayer->hasIdenticalCardOnTable(this)) {
        throw TwoSameOnTableException();
    }
    gameTable()->playerPlayCardOnTable(this, targetPlayer);
}


