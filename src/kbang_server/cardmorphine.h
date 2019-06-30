#ifndef CARDMORPHIN_H
#define CARDMORPHIN_H

#include "playingcard.h"

class CardMorphine : public PlayingCard {
public:
    CardMorphine(Game* game, int id, CardSuit cardSuit, CardRank cardRank);
    CardColor color() const;
    void play();
    virtual void registerPlayer(Player* player);
    virtual void unregisterPlayer(Player* player);
private:
    bool m_isOwnerLiving;
}; 

#endif // CARDMORPHIN_H
