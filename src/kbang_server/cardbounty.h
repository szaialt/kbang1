#ifndef CARDBOUNTY_H
#define CARDBOUNTY_H

#include "playingcard.h"

class CardBounty : public PlayingCard {
public:
    CardBounty(Game* game, int id, CardSuit cardSuit, CardRank cardRank);
    CardColor color() const;
    void play(Player* targetPlayer);
}; 

#endif // CARDBOUNTY_H
