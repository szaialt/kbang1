#ifndef CHARACTERDYNAMITEDICK_H
#define CHARACTERDYNAMITEDICK_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterDynamiteDick : public CharacterBase
{
Q_OBJECT
public:
    CharacterDynamiteDick(QObject* parent);
    virtual int maxLifePoints() const;
    virtual void useAbility();
    
};

#endif // CHARACTERDYNAMITEDICK_H
