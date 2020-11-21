#ifndef CHARACTERCRAZYHORSE_H
#define CHARACTERCRAZYHORSE_H

#include "characterbase.h"

class CharacterCrazyHorse : public CharacterBase
{
Q_OBJECT
public:
    CharacterCrazyHorse(QObject *parent);
    virtual void useAbility(QList<PlayingCard*> cards);
 
};

#endif // CHARACTERCRAZYHORSE_H
