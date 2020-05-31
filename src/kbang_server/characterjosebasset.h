#ifndef CHARACTERJOSEYBASSET_H
#define CHARACTERJOSEYBASSET_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterJoseBasset : public CharacterBase
{
Q_OBJECT
public:
    CharacterJoseBasset(QObject* parent);
    virtual void draw(bool specialDraw);
    virtual void useAbility();
    virtual void resetAbility();
protected: 
    bool m_canUseAbility;
};

#endif // CHARACTERJOSEYBASSET_H
