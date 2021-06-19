#ifndef CARDDYNAMITE_H
#define CARDDYNAMITE_H

#include "playingcard.h"
#include "checkdeckresulthandler.h"

class CardDynamite : public PlayingCard, public CheckDeckResultHandler
{
public:
    CardDynamite(Game *game, int id, CardSuit suit, CardRank rank, int PredrawCheck);
    virtual ~CardDynamite();

    virtual CardColor color() const;
    virtual void play();
    //virtual void play(Player* targetPlayer);
    virtual void checkResult(bool result);
    virtual void registerPlayer(Player* player);
    virtual void unregisterPlayer(Player* player);
    static bool checkDynamite(PlayingCard*);
};

#endif // CARDDYNAMITE_H
