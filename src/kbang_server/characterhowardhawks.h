#ifndef CHARACTERHOWARDHAWKS_H
#define CHARACTERHOWARDHAWKS_H

#include "characterbase.h"

class CharacterHowardHawks : public CharacterBase
{
Q_OBJECT
public:
    CharacterHowardHawks(QObject *parent);
    virtual void useAbility(QList<PlayingCard*> cards, Player* targetPlayer);
    void resetAbility();
protected:
    bool m_canUseAbility;
};

#endif // CHARACTERHOWARDHAWKS_H
