#ifndef CARDTHIEF_H
#define CARDTHIEF_H

#include "playingcard.h"

class CardThief : public PlayingCard {
public:
    CardThief(Game* game, int id, CardSuit cardSuit, CardRank cardRank);
    virtual void play(QList<PlayingCard*> targetCards);
}; 

#endif // CARDTHIEF_H
