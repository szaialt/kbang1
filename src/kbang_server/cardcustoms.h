#ifndef CARDCUSTOMS_H
#define CARDCUSTOMS_H

#include "cardmultishoot.h"

class Player;

class CardCustoms : public CardMultiShoot
{
Q_OBJECT;
public:
    CardCustoms(Game* game, int id, CardSuit, CardRank);
    virtual ~CardCustoms();
    virtual CardColor color();
    virtual void play(); 

    virtual void respondPass();
    virtual void respondCard(PlayingCard* targetCard);
    virtual ReactionType reactionType() const { return REACTION_CUSTOMS; }
    virtual Player* causedBy() const { return mp_shootingPlayer; }
protected:
    virtual Player* selectPlayer();
};


#endif // CARDCUSTOMS_H
