#ifndef CHARACTERTUCOELFEO_H
#define CHARACTERTUCOELFEO_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"
#include "reactionhandler.h"

class CharacterTucoElFeo : public CharacterBase
{
Q_OBJECT
public:
    CharacterTucoElFeo(QObject* parent);
    int items();
    void resetAbility();
    void itemToken();
    const int itemNumber = 2;
protected:
    int m_items;
};

#endif // CHARACTERTUCOELFEO_H
