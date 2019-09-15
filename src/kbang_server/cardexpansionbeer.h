#ifndef CARDEXPANSIONBEER_H
#define CARDEXPANSIONBEER_H
#include "cardbeer.h"

class CardExpansionBeer : public CardBeer {

Q_OBJECT; 
public:
    
    CardExpansionBeer(Game* game, int id, BeerType type, CardSuit cardSuit, CardRank cardRank);
    ~CardExpansionBeer();

    virtual CardColor color();
    virtual void play(Player* targetPlayer);
    virtual void play(PlayingCard* targetCard);
    virtual void play();

};

#endif // CARDEXPANSIONBEER_H
