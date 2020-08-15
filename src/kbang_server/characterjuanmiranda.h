#ifndef CHARACTERJUANMIRANDA_H
#define CHARACTERJUANMIRANDA_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterJuanMiranda : public CharacterBase
{
Q_OBJECT
public:
    CharacterJuanMiranda(QObject* parent);
    virtual int maxLifePoints() const;
};

#endif // CHARACTERJUANMIRANDA_H
