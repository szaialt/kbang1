#ifndef CHARACTERLINDAVIVENDA_H
#define CHARACTERLINDAVIVENDA_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterLindaVivenda : public CharacterBase
{
Q_OBJECT
public:
    CharacterLindaVivenda(QObject* parent);
    virtual int maxLifePoints() const;
};

#endif // CHARACTERLINDAVIVENDA_H
