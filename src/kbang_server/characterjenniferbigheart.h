#ifndef CHARACTERJENNIFERBIGHEART_H
#define CHARACTERJENNIFERBIGHEART_H

#include "characterbase.h"

class CharacterJenniferBigHeart: public CharacterBase
{
Q_OBJECT
public:
    CharacterJenniferBigHeart(QObject *parent);
    virtual void useAbility(QList<PlayingCard*> cards, Player* targetPlayer);
};

#endif // CHARACTERJENNIFERBIGHEART_H
