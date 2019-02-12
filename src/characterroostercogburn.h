#ifndef CHARACTERROOSTERCOGBURN_H
#define CHARACTERROOSTERCOGBURN_H

#include "characterbase.h"
#include "cardhiddenweapon.h"

class CharacterRoosterCogburn : public CharacterBase
{
Q_OBJECT
public:
    CharacterRoosterCogburn(QObject *parent);
    virtual void setPlayer(Player* player);

private:
    CardHiddenWeapon* mp_hiddenweapon;
};

#endif // CHARACTERROOSTERCOGBURN_H
