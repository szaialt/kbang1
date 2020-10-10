#ifndef CHARACTERGREENKATEJANET_H
#define CHARACTERGREENKATEJANET_H

#include "characterbase.h"

class CharacterGreenKateJanet : public CharacterBase
{
Q_OBJECT
public:
    CharacterGreenKateJanet(QObject *parent);
    virtual void useAbility(QList<PlayingCard*> cards, Player* targetPlayer);

};

#endif // CHARACTERGREENKATEJANET_H
