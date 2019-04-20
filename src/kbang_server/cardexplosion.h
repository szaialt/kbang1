#ifndef CARDEXPLOSION_H
#define CARDEXPLOSION_H

#include "cardmultishoot.h" 

class CardExplosion : public PlayingCard {
    
public:
    CardExplosion(Game* game, int id, CardSuit cardSuit, CardRank cardRank);

    virtual ~CardExplosion(){}

    virtual void play();
    
protected:
    void playInNextDirection(Player* player);
    
    Player* mp_shootingPlayer;
    Player* mp_requestedPlayer;
};

#endif //CARDEXPLOSION_H
