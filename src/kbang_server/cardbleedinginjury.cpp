#include "cardbleedinginjury.h"
#include "gametable.h"

CardBleedingInjury::CardBleedingInjury(Game* game, int id, CardSuit cardSuit, CardRank cardRank):
        PlayingCard(game, id, CARD_BLEEDING_INJURY, cardSuit, cardRank)
{
}

CardColor CardBleedingInjury::color() const {
    return COLOR_BLUE;
}

void CardBleedingInjury::play(Player* targetPlayer)
{
    gameCycle()->assertTurn();
    assertInHand();
    if (targetPlayer->hasIdenticalCardOnTable(this)) {
        throw TwoSameOnTableException();
    }
    gameTable()->playerPlayCardOnTable(this, targetPlayer);
}
 
