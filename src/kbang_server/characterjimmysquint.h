#ifndef CHARACTERJIMMYSQUINT_H
#define CHARACTERJIMMYSQUINT_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterJimmySquint: public CharacterBase
{
Q_OBJECT
public:
    CharacterJimmySquint(QObject* parent);
    virtual int maxLifePoints() const;
    virtual void playCard(PlayingCard* card, Player* targetPlayer);
};

#endif // CHARACTERJIMMYSQUINT_H
