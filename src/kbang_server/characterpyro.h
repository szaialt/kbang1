#ifndef CHARACTERPYRO_H
#define CHARACTERPYRO_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"
#include "playingcard.h"

class CharacterPyro: public CharacterBase
{
Q_OBJECT
public:
    CharacterPyro(QObject* parent);
    virtual void useAbility(QList<PlayingCard*> cards);
    
};

#endif // CHARACTERPYRO_H
