#include "cardcharm.h"
#include "gametable.h"

CardCharm::CardCharm(Game* game, int id, CardSuit cardSuit, CardRank cardRank):
        PlayingCard(game, id, CARD_CHARM, cardSuit, cardRank)
{
}

void CardCharm::play(Player* targetPlayer)
{
    gameCycle()->assertTurn();
    assertInHand();
    targetPlayer->charm();
}
 
