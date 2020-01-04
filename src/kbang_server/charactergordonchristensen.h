#ifndef CHARACTERGORDONCHRISTENSEN_H
#define CHARACTERGORDONCHRISTENSEN_H

#include "characterbase.h"

class CharacterGordonChristensen : public CharacterBase
{
Q_OBJECT
public:
    CharacterGordonChristensen(QObject *parent);
    virtual void useAbility(QList<PlayingCard*> cards);
    void resetAbility();
protected:
    int m_times;

};

#endif // CHARACTERGORDONCHRISTENSEN_H
