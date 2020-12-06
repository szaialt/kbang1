#ifndef CHARACTERONEEYEDJACK_H
#define CHARACTERONEEYEDJACK_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterOneEyedJack : public CharacterBase
{
Q_OBJECT
public:
    CharacterOneEyedJack(QObject* parent);
    virtual int maxLifePoints() const;
};

#endif // CHARACTERONEEYEDJACK_H
