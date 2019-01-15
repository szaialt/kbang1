#include "cardghost.h"
#include "gametable.h"

CardGhost::CardGhost(Game* game, int id, CardSuit cardSuit, CardRank cardRank):
        PlayingCard(game, id, CARD_GHOST, cardSuit, cardRank)
{
}

CardColor CardGhost::color() const {
    return COLOR_BLUE;
}

void CardGhost::play(Player* targetPlayer)
{
    gameCycle()->assertTurn();
    assertInHand();
    if (targetPlayer->isAlive()) throw BadUsageException();
    if (targetPlayer->hasIdenticalCardOnTable(this)) {
        throw TwoSameOnTableException();
    }
    gameTable()->playerPlayCardOnTable(this, targetPlayer);
    targetPlayer->setAlive(true);
}
 
void CardGhost::unregisterPlayer(Player* player){
    player->setAlive(false);
}
