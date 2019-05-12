#ifndef CARDBLEEDINGINJURY_H
#define CARDBLEEDINGINJURY_H

#include "playingcard.h"

class CardBleedingInjury : public PlayingCard {
public:
    CardBleedingInjury(Game* game, int id, CardSuit cardSuit, CardRank cardRank);
    CardColor color() const;
    void play(Player* targetPlayer);
}; 

#endif // CARDBLEEDINGINJURY_H
