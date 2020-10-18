#ifndef CHARACTEROSCARRODRIGUEZ_H
#define CHARACTEROSCARRODRIGUEZ_H

#include "characterbase.h"

class Player;

class CharacterOscarRodriguez : public CharacterBase
{
Q_OBJECT
public:
    CharacterOscarRodriguez(QObject *parent);
    virtual void useAbility(Player* targetPlayer);
private:
    Player* mp_targetPlayer;
};

#endif // CHARACTEROSCARRODRIGUEZ_H
