#ifndef CARDPEACEPIPE_H
#define CARDPEACEPIPE_H

#include "playingcard.h"

class CardPeacePipe : public PlayingCard {
public:
    CardPeacePipe(Game* game, int id, CardSuit cardSuit, CardRank cardRank);
    CardColor color() const;
    void play();
}; 

#endif // CARDPEACEPIPE_H
