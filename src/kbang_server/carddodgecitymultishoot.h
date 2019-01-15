#ifndef CARD_DODGE_CITY_MULTISHOOT_H
#define CARD_DODGE_CITY_MULTISHOOT_H

#include "cardmultishoot.h"

class CardDodgeCityMultiShoot : public CardMultiShoot
{
    Q_OBJECT;

public:
    CardDodgeCityMultiShoot(Game* game, int id, CardMultiShoot::Type type, CardSuit cardSuit, CardRank cardRank);
    virtual CardColor color() const;
    virtual void play();
    virtual void takeGreenCardEffect(); 
    virtual void checkResult(bool result);
    virtual ReactionType reactionType() const;
};

#endif // CARD_DODGE_CITY_MULTISHOOT_H
