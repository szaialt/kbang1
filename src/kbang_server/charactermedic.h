#ifndef CHARACTERMEDIC_H
#define CHARACTERMEDIC_H

#include "characterbase.h"

class CharacterMedic : public CharacterBase
{
Q_OBJECT
public:
    CharacterMedic(QObject *parent);
    virtual void useAbility(QList<PlayingCard*> cards, Player* targetPlayer);

};

#endif // CHARACTERMEDIC_H
