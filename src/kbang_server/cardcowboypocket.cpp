#include "cardcowboypocket.h"
#include "gametable.h"

CardCowboyPocket::CardCowboyPocket(Game* game, int id, CardSuit cardSuit, CardRank cardRank):
        PlayingCard(game, id, CARD_COWBOY_POCKET, cardSuit, cardRank)
{
}

CardColor CardCowboyPocket::color() const {
    return COLOR_BLUE;
}

void CardCowboyPocket::play()
{
    playAsBlueCard();
}
 
