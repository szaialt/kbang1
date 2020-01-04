#ifndef CHARACTERAUNTIEANGELICI_H
#define CHARACTERAUNTIEANGELICI_H

#include "characterbase.h"

class CharacterAuntieAngelici : public CharacterBase
{
Q_OBJECT
public:
    CharacterAuntieAngelici(QObject *parent);
    virtual int maxLifePoints() const;
    virtual void useAbility(QList<PlayingCard*> cards);
    void resetAbility();

};

#endif // CHARACTERAUNTIEANGELICI_H
