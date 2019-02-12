#include "cardpeacepipe.h"
#include "gametable.h"

CardPeacePipe::CardPeacePipe(Game* game, int id, CardSuit cardSuit, CardRank cardRank):
        PlayingCard(game, id, CARD_PEACE_PIPE, cardSuit, cardRank)
{
}

CardColor CardPeacePipe::color() const {
    return COLOR_BLUE;
}

void CardPeacePipe::play()
{
    playAsBlueCard();
}
 
