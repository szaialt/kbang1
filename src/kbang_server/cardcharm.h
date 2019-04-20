#ifndef CARDCHARM_H
#define CARDCHARM_H

#include "playingcard.h"

class CardCharm : public PlayingCard {
public:
    CardCharm(Game* game, int id, CardSuit cardSuit, CardRank cardRank);
    void play(Player* targetPlayer);
}; 

#endif // CARDCHARM_H
