#ifndef CARDDIRTYJOB_H
#define CARDDIRTYJOB_H

#include "playingcard.h"

class CardDirtyJob : public PlayingCard {
public:
    CardDirtyJob(Game* game, int id, CardSuit cardSuit, CardRank cardRank);
    void play(Player* targetPlayer);
}; 

#endif // CARDDIRTYJOB_H
