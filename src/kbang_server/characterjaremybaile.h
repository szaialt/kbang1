#ifndef CHARACTERJAREMYBAILE_H
#define CHARACTERJAREMYBAILE_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterJaremyBaile : public CharacterBase
{
Q_OBJECT
public:
    CharacterJaremyBaile(QObject* parent);
    virtual int maxLifePoints() const;
};

#endif // CHARACTERJAREMYBAILE_H
