#ifndef CARDGHOST_H
#define CARDGHOST_H

#include "playingcard.h"

class CardGhost : public PlayingCard {
public:
    CardGhost(Game* game, int id, CardSuit cardSuit, CardRank cardRank);
    CardColor color() const;
    void play(Player* targetPlayer);
    virtual void unregisterPlayer(Player* player);
}; 

#endif // CARDGHOST_H
