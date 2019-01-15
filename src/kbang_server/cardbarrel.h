#ifndef CARDBARREL_H
#define CARDBARREL_H

#include "playingcard.h"

class CheckDeckResultHandler;

class CardBarrel : public PlayingCard
{
Q_OBJECT;
public:
    CardBarrel(Game *game, int id, CardSuit, CardRank);
    virtual ~CardBarrel();

    virtual CardColor color() const;
    virtual void play();
    virtual void registerPlayer(Player* player);
    virtual void unregisterPlayer(Player* player);

    void check(CheckDeckResultHandler*);

    static bool checkBarrel(PlayingCard*);
};


#endif // CARDBARREL_H
