#ifndef CHARACTERJACKBROWN_H
#define CHARACTERJACKBROWN_H

#include "characterbase.h"

class CharacterJackBrown : public CharacterBase
{
Q_OBJECT
public:
    CharacterJackBrown(QObject *parent);
    virtual void useAbility(QList<PlayingCard*> cards);

};

#endif // CHARACTERJACKBROWN_H
