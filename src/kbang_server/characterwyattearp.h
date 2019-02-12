#ifndef CHARACTERWYATTEARP_H
#define CHARACTERWYATTEARP_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterWyattEarp : public CharacterBase
{
Q_OBJECT
public:
    CharacterWyattEarp(QObject* parent);
    virtual void useAbility(QList<PlayingCard*> cards, Player* targetPlayer);
};

#endif // CHARACTERWYATTEARP_H
