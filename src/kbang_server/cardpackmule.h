#ifndef CARDPACKMULE_H
#define CARDPACKMULE_H

#include "playingcard.h"
#include "player.h"

class CardPackMule : public PlayingCard {
public:
    CardPackMule(Game* game, int id, CardSuit cardSuit, CardRank cardRank);
    CardColor color() const;
    void play();
}; 

#endif // CARDPACKMULE_H
