#ifndef CARDSTEROID_H
#define CARDSTEROID_H

#include "playingcard.h"

class CardSteroid : public PlayingCard
{
Q_OBJECT;
public:
    CardSteroid(Game *game, int id, CardSuit, CardRank);
    virtual ~CardSteroid();

    virtual CardColor color() const;
    virtual void play();
};


#endif // CARDSTEROID_H
