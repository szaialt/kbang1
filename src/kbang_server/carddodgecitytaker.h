//carddodgecitytaker.h
#ifndef CARD_DODGE_CITY_TAKER_H
#define CARD_DODGE_CITY_TAKER_H

#include "cardtaker.h"

class CardDodgeCityTaker : public CardTaker
{
public:
    CardDodgeCityTaker(Game *game, int id, CardTakerType, CardSuit, CardRank);
    virtual CardColor color() const;
    virtual void play();
    virtual void play(PlayingCard* targetCard, Player* targetPlayer);
    virtual void play(Player* targetPlayer);
    virtual void play(PlayingCard* targetCard);
    virtual void play(QList<PlayingCard*> targetCards);
    virtual bool checkTargetCards(QList<PlayingCard*> targetCards);
};

#endif // CARD_DODGE_CITY_TAKER_H
