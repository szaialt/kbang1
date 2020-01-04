#ifndef CHARACTERGVBLACK_H
#define CHARACTERGVBLACK_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterGVBlack : public CharacterBase
{
Q_OBJECT
public:
    CharacterGVBlack(QObject* parent);
    virtual void useAbility(QList<PlayingCard*> cards);
};

#endif // CHARACTERGVBLACK_H
