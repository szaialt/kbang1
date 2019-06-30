#include "cardsteroid.h"
#include "player.h"
#include "gametable.h"
#include "gamecycle.h"
#include "gameexceptions.h"
#include "characterbase.h"

CardSteroid::CardSteroid(Game *game, int id, CardSuit suit, CardRank rank):
        PlayingCard(game, id, CARD_STEROID, suit, rank)
{
}

CardSteroid::~CardSteroid()
{
}

CardColor CardSteroid::color() const{
    return COLOR_POSITIVE_GREY;
}

void CardSteroid::play()
{
    playAsBlueCard();
}


