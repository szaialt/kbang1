#include "cardbounty.h"
#include "gametable.h"

CardBounty::CardBounty(Game* game, int id, CardSuit cardSuit, CardRank cardRank):
        PlayingCard(game, id, CARD_BOUNTY, cardSuit, cardRank)
{
}

CardColor CardBounty::color() const {
    return COLOR_BLUE;
}

void CardBounty::play(Player* targetPlayer)
{
    gameCycle()->assertTurn();
    assertInHand();
    if (targetPlayer->hasIdenticalCardOnTable(this)) {
        throw TwoSameOnTableException();
    }
    gameTable()->playerPlayCardOnTable(this, targetPlayer);
}
 
