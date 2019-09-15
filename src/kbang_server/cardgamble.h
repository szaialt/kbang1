#ifndef CARDGAMBLE_H
#define CARDGAMBLE_H

#include "playingcard.h"
#include "checkdeckresulthandler.h"

class CardGamble : public PlayingCard, public CheckDeckResultHandler
{
public:
    CardGamble(Game *game, int id, CardSuit suit, CardRank rank, int PredrawCheck);
    virtual ~CardGamble();

    virtual CardColor color() const;
    virtual void play();
    virtual void checkResult(bool result);
    virtual void registerPlayer(Player* player);
    virtual void unregisterPlayer(Player* player);
    static bool check(PlayingCard*);
};

#endif // CARDGAMBLE_H
