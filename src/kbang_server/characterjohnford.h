#ifndef CHARACTERJOHNFORD_H
#define CHARACTERJOHNFORD_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterJohnFord : public CharacterBase
{
Q_OBJECT
public:
    CharacterJohnFord(QObject* parent);
    virtual void useAbility(QList<PlayingCard*> cards, Player* targetPlayer);
};

#endif // CHARACTERJOHNFORD_H
