#ifndef CHARACTERCOWBOY_H
#define CHARACTERCOWBOY_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterCowboy : public CharacterBase
{
Q_OBJECT
public:
    CharacterCowboy(QObject* parent);
    virtual int maxLifePoints() const;
};

#endif // CHARACTERCOWBOY_H
