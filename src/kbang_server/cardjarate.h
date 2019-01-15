#ifndef CARDJARATE_H
#define CARDJARATE_H

#include "playingcard.h"

class CardJarate : public PlayingCard {
public:
    CardJarate(Game* game, int id, CardSuit cardSuit, CardRank cardRank);
    CardColor color() const;
    void play(Player* targetPlayer);
}; 

#endif // CARDJARATE_H
