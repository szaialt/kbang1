#ifndef CARD_DODGE_CITY_BANG_H
#define CARD_DODGE_CITY_BANG_H

#include "cardbang.h"

class CardDodgeCityBang : public CardBang {
public:
    CardDodgeCityBang(Game *game, int id, BangType type, CardSuit, CardRank);
    virtual CardColor color() const;
    virtual void play(); 
    virtual void play(Player* targetPlayer);
protected:
    virtual void controlCard();
    virtual void controlTarget(Player *targetPlayer);
    virtual void shot(Player *targetPlayer);
};

#endif
