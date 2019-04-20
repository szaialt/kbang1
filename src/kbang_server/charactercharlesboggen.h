#ifndef CHARACTERCHARLESBOGGEN_H
#define CHARACTERCHARLESBOGGEN_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"
#include "reactionhandler.h"

class CharacterCharlesBoggen : public CharacterBase
{
Q_OBJECT
public: 
    CharacterCharlesBoggen(QObject* parent);
    virtual void respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard);
};

#endif // CHARACTERCHARLESBOGGEN_H
