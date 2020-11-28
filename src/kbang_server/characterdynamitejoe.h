#ifndef CHARACTERDYNAMITEJOE_H
#define CHARACTERDYNAMITEJOE_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterDynamiteJoe : public CharacterBase
{
Q_OBJECT
public:
    CharacterDynamiteJoe(QObject* parent);
    virtual int maxLifePoints() const;
    virtual void useAbility();
    
};

#endif // CHARACTERDYNAMITEJOE_H
