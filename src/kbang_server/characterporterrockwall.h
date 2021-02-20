#ifndef CHARACTERPORTERROCKWALL_H
#define CHARACTERPORTERROCKWALL_H

#include "characterbase.h"

class Player;

class CharacterPorterRockwall : public CharacterBase
{
Q_OBJECT
public:
    CharacterPorterRockwall(QObject *parent);
    virtual void useAbility(QList<PlayingCard*> cards, Player* targetPlayer);
    void resetAbility();
protected:
    PlayingCard* mp_bang;
};

#endif // CHARACTERPORTERROCKWALL_H
