#include "cardmemento.h"
#include "player.h"
#include "gametable.h"
#include "gamecycle.h"
#include "gameexceptions.h"
#include "characterbase.h"

CardMemento::CardMemento(Game *game, int id, CardSuit suit, CardRank rank):
        PlayingCard(game, id, CARD_MEMENTO, suit, rank)
{
}

CardMemento::~CardMemento()
{
}

CardColor CardMemento::color() const{
    return COLOR_BLUE;
}

void CardMemento::play()
{
    playAsBlueCard();
}


void CardMemento::registerPlayer(Player*)
{
}

void CardMemento::unregisterPlayer(Player*)
{
}


