#ifndef CHARACTERJUANMIRANDA_H
#define CHARACTERJUANMIRANDA_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterJuanMiranda : public CharacterBase
{
Q_OBJECT
public:
    CharacterJuanMiranda(QObject* parent);
    virtual void respondPass(ReactionHandler* reactionHandler);
private:
    bool check(PlayingCard* card);
};

#endif // CHARACTERJUANMIRANDA_H
