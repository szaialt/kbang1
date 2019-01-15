#ifndef CHARACTERSCOUT_H
#define CHARACTERSCOUT_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"
#include "reactionhandler.h"

class CharacterScout : public CharacterBase
{
Q_OBJECT
public: 
    CharacterScout(QObject* parent);
    virtual int maxLifePoints() const;
    virtual void respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard);
};

#endif // CHARACTERSCOUT_H
