#ifndef CHARACTERDALTONGANG_H
#define CHARACTERDALTONGANG_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterDaltonGang : public CharacterBase
{
Q_OBJECT
public:
    CharacterDaltonGang(QObject* parent);
    virtual int maxLifePoints() const;
};

#endif // CHARACTERDALTONGANG_H
