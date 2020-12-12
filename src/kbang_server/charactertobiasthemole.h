#ifndef CHARACTERTOBIASTHEMOLE_H
#define CHARACTERTOBIASTHEMOLE_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterTobiasTheMole : public CharacterBase
{
Q_OBJECT
public:
    CharacterTobiasTheMole(QObject* parent);
    virtual int maxLifePoints() const;
};

#endif // CHARACTERTOBIASTHEMOLE_H
