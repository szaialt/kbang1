#ifndef CARDHEADACHE_H
#define CARDHEADACHE_H

#include "playingcard.h"

class CardHeadache : public PlayingCard {
public:
    CardHeadache(Game* game, int id, CardSuit cardSuit, CardRank cardRank);
    CardColor color() const;
    void play(Player* targetPlayer);
}; 

#endif // CARDHEADACHE_H
