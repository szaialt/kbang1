#ifndef CHARACTEREDWARDANGLE_H
#define CHARACTEREDWARDANGLE_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"
#include "playingcard.h"

class CharacterEdwardAngle : public CharacterBase
{
Q_OBJECT
public:
    CharacterEdwardAngle(QObject* parent);
    virtual void useAbility();

    
};

#endif // CHARACTEREDWARDANGLE_H
