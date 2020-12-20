#ifndef CHARACTERNINANINELIVES_H
#define CHARACTERNINANINELIVES_H

#include "characterbase.h"

class CharacterNinaNineLives : public CharacterBase
{
Q_OBJECT
public:
    CharacterNinaNineLives(QObject *parent);
    virtual int maxLifePoints() const;
    bool check(PlayingCard* card);
    bool canUseAbility();
protected:
    int m_times;
};

#endif // CHARACTERNINANINELIVES_H
