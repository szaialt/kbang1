#ifndef CHARACTERVIENNA_H
#define CHARACTERVIENNA_H

#include "characterbase.h"

class CharacterVienna : public CharacterBase
{
Q_OBJECT
public:
    CharacterVienna(QObject *parent);
    virtual void useAbility(QList<PlayingCard*> cards, Player* targetPlayer);
    void resetAbility();
private:
    bool m_canUseAbility;
};

#endif // CHARACTERVIENNA_H
