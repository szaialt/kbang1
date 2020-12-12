#ifndef CHARACTERPRESTONPRESBYOPE_H
#define CHARACTERPRESTONPRESBYOPE_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterPrestonPresbyope  : public CharacterBase
{
Q_OBJECT
public:
    CharacterPrestonPresbyope(QObject* parent);
    virtual int maxLifePoints() const;
    virtual void useAbility(QList<PlayingCard*> cards);
};

#endif // CHARACTERPRESTONPRESBYOPE_H
