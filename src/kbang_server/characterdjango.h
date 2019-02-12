#ifndef CHARACTERDJANGO_H
#define CHARACTERDJANGO_H

#include "characterbase.h"

class Player;

class CharacterDjango : public CharacterBase
{
Q_OBJECT
public:
    CharacterDjango(QObject *parent);
    virtual void useAbility(QList<PlayingCard*> cards);
    void resetAbility();
protected:
    PlayingCard* mp_gatling;
    bool m_canUseAbility;
};

#endif // CHARACTERDJANGO_H
