#ifndef CARD_DODGE_CITY_BEER_H
#define CARD_DODGE_CITY_BEER_H

#include "cardbeer.h"

class CardDodgeCityBeer : public CardBeer
{
    Q_OBJECT;
public:
    CardDodgeCityBeer(Game* game, int id, BeerType type, CardSuit cardSuit, CardRank cardRank);
    virtual CardColor color() const;
    virtual void play();
    virtual void play(PlayingCard* targetCard);
    virtual void play(PlayingCard* targetCard, Player* targetPlayer);
    virtual void takeGreenCardEffect();
};

#endif // CARD_DODGE_CITY_BEER_H
