#ifndef CARDHIDDENWEAPON_H
#define CARDHIDDENWEAPON_H

#include "playingcard.h"

class CardHiddenWeapon : public PlayingCard
{
Q_OBJECT;
public:
    CardHiddenWeapon(Game *game, int id, CardSuit, CardRank);
    virtual ~CardHiddenWeapon();

    virtual CardColor color() const;
    virtual void play();
    virtual void registerPlayer(Player* player);
    virtual void unregisterPlayer(Player* player);
   
};


#endif // CARDHIDDENWEAPON_H
