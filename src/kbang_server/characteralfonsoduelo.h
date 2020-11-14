#ifndef CHARACTERALFONSODUELO_H
#define CHARACTERALFONSODUELO_H

#include "characterbase.h"

class CharacterAlfonsoDuelo : public CharacterBase
{
Q_OBJECT
public:
    CharacterAlfonsoDuelo(QObject *parent);
    virtual void useAbility(QList<PlayingCard*> cards, Player* targetPlayer);

};

#endif // CHARACTERALFONSODUELO_H
