#ifndef CARDMEMENTO_H
#define CARDMEMENTO_H

#include "playingcard.h"

class CardMemento : public PlayingCard
{
Q_OBJECT;
public:
    CardMemento(Game *game, int id, CardSuit, CardRank);
    virtual ~CardMemento();

    virtual CardColor color() const;
    virtual void play();
    virtual void registerPlayer(Player* player);
    virtual void unregisterPlayer(Player* player);
   
};


#endif // CARDMEMENTO_H
