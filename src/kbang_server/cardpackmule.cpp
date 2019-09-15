#include "cardpackmule.h"
#include "gametable.h"

CardPackMule::CardPackMule(Game* game, int id, CardSuit cardSuit, CardRank cardRank):
        PlayingCard(game, id, CARD_PACK_MULE, cardSuit, cardRank)
{
}

CardColor CardPackMule::color() const {
    return COLOR_BLUE;
}

void CardPackMule::play()
{
    playAsBlueCard();
}
 
