#ifndef CARDCOWBOYPOCKET_H
#define CARDCOWBOYPOCKET_H

#include "playingcard.h"

class CardCowboyPocket : public PlayingCard {
public:
    CardCowboyPocket(Game* game, int id, CardSuit cardSuit, CardRank cardRank);
    CardColor color() const;
    void play();
}; 

#endif // CARDCOWBOYPOCKET_H
