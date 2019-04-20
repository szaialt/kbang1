#ifndef CHARACTERWHITEWOLF_H
#define CHARACTERWHITEWOLF_H

#include "characterbase.h"

class CharacterWhiteWolf : public CharacterBase
{
Q_OBJECT
public:
    CharacterWhiteWolf(QObject *parent);
    virtual void useAbility(QList<PlayingCard*> cards, Player* targetPlayer);

};

#endif // CHARACTERWHITEWOLF_H
