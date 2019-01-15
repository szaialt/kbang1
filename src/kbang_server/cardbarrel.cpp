#include "cardbarrel.h"
#include "player.h"
#include "gametable.h"
#include "gamecycle.h"
#include "gameexceptions.h"
#include "characterbase.h"

CardBarrel::CardBarrel(Game *game, int id, CardSuit suit, CardRank rank):
        PlayingCard(game, id, CARD_BARREL, suit, rank)
{
}

CardBarrel::~CardBarrel()
{
}

CardColor CardBarrel::color() const{
    return COLOR_BLUE;
}

void CardBarrel::play()
{
    playAsBlueCard();
}


void CardBarrel::registerPlayer(Player*)
{
}

void CardBarrel::unregisterPlayer(Player*)
{
}


void CardBarrel::check(CheckDeckResultHandler* resultHandler)
{
    gameCycle()->checkDeck(owner(), this, *CardBarrel::checkBarrel, resultHandler);
}

bool CardBarrel::checkBarrel(PlayingCard* card)
{
    return  (card->suit() == SUIT_HEARTS);
}
