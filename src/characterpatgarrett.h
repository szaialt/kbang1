#ifndef CHARACTERPATGARRETT_H
#define CHARACTERPATGARRETT_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterPatGarrett : public CharacterBase
{
Q_OBJECT
public:
    CharacterPatGarrett(QObject* parent);
    virtual void useAbility(QList<PlayingCard*> cards, Player* targetPlayer);
};

#endif // CHARACTERPATGARRETT_H 
