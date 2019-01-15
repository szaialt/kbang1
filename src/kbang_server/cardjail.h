#ifndef CARDJAIL_H
#define CARDJAIL_H

#include "playingcard.h"
#include "checkdeckresulthandler.h"

class CardJail : public PlayingCard, public CheckDeckResultHandler
{
public:
    CardJail(Game *game, int id, CardSuit suit, CardRank rank, int PredrawCheck);
    ~CardJail();

    virtual CardColor color() const;

    virtual void play();
    virtual void play(Player* targetPlayer);
    virtual void checkResult(bool result);

    virtual void registerPlayer(Player* player);
    virtual void unregisterPlayer(Player* player);

    static bool checkJail(PlayingCard*);

};

#endif // CARDJAIL_H
