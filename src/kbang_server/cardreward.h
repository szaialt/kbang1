#ifndef CARDREWARD_H
#define CARDREWARD_H

#include "playingcard.h"

class CardReward : public PlayingCard {
public:
    CardReward(Game* game, int id, CardSuit cardSuit, CardRank cardRank);
    CardColor color() const;
    void play(Player* targetPlayer);
};

#endif // CARDREWARD_H
