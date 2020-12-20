#ifndef CHARACTERNELLYCHOSECHAIR_H
#define CHARACTERNELLYCHOSECHAIR_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"
#include "playingcard.h"

class CharacterNellyChoseChair : public CharacterBase
{
Q_OBJECT
public:
    CharacterNellyChoseChair(QObject* parent);
    virtual void useAbility(Player* targetPlayer);

    
};

#endif // CHARACTERNELLYCHOSECHAIR_H
