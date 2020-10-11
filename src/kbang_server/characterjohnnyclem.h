#ifndef CHARACTERJOHNNYCLEM_H
#define CHARACTERJOHNNYCLEM_H

#include "characterbase.h"

class CharacterJohnnyClem : public CharacterBase
{
Q_OBJECT
public:
    CharacterJohnnyClem(QObject *parent);
    virtual int maxLifePoints() const;
    virtual void useAbility(QList<PlayingCard*> cards);

};

#endif // CHARACTERJOHNNYCLEM_H
