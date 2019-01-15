#ifndef CARDTELEPORT_H
#define CARDTELEPORT_H

#include "playingcard.h"
#include "checkdeckresulthandler.h"

class CardTeleport : public PlayingCard, public CheckDeckResultHandler
{
public:
    CardTeleport(Game *game, int id, CardSuit suit, CardRank rank, int PredrawCheck);
    ~CardTeleport();

    virtual CardColor color() const;

    virtual void play();
    virtual void play(Player* targetPlayer);
    virtual void checkResult(bool result);

    virtual void registerPlayer(Player* player);
    virtual void unregisterPlayer(Player* player);

    static bool check(PlayingCard*);

};

#endif // CARDTELEPORT_H
