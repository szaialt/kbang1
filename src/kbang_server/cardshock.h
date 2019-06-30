#ifndef CARDSHOCK_H
#define CARDSHOCK_H

#include "playingcard.h"

class CardShock : public PlayingCard {
    Q_OBJECT
public:
    CardShock(Game* game, int id, CardSuit cardSuit, CardRank cardRank);
    CardColor color() const;
    void play(Player* targetPlayer);
};

#endif // CARDSHOCK_H
