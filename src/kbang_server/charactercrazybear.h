#ifndef CHARACTERCRAZYBEAR_H
#define CHARACTERCRAZYBEAR_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterCrazyBear : public CharacterBase
{
Q_OBJECT
public:
    CharacterCrazyBear(QObject* parent);
    int injury();
};

#endif // CHARACTERCRAZYBEAR_H
