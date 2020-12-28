#ifndef CHARACTERBRUCELING_H
#define CHARACTERBRUCELING_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"
#include "reactionhandler.h"

class CharacterBruceLing : public CharacterBase
{
Q_OBJECT
public:
    CharacterBruceLing(QObject* parent);
    int items();
    void resetAbility();
    void itemToken();
    const int itemNumber = 2;
protected:
    int m_items;
};

#endif // CHARACTERBRUCELING_H
