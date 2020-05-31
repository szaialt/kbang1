#ifndef CHARACTERCRAZYWOLF_H
#define CHARACTERCRAZYWOLF_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"
#include "reactionhandler.h"

class CharacterCrazyWolf : public CharacterBase
{
Q_OBJECT
public:
    CharacterCrazyWolf(QObject* parent);
    virtual void respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard);
};

#endif // CHARACTERCRAZYWOLF_H
