#ifndef CHARACTERCAPTBARRETT_H
#define CHARACTERCAPTBARRETT_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterCaptBarret : public CharacterBase
{
Q_OBJECT
public:
    CharacterCaptBarret(QObject* parent);
    virtual int maxLifePoints() const;
};

#endif // CHARACTERCAPTBARRETT_H
