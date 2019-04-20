#ifndef CHARACTERJONATHHEXX_H
#define CHARACTERJONATHHEXX_H

#include "characterbase.h"

class CharacterJonathHexx : public CharacterBase
{
Q_OBJECT
public:
    CharacterJonathHexx(QObject *parent);
    virtual void useAbility(QList<PlayingCard*> cards, Player* targetPlayer);

};

#endif // CHARACTERJONATHHEXX_H
