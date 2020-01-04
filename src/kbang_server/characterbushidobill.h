#ifndef CHARACTERBUSHIDOBILL_H
#define CHARACTERBUSHIDOBILL_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"
#include "reactionhandler.h"

class CharacterBushidoBill : public CharacterBase
{
Q_OBJECT
public: 
    CharacterBushidoBill(QObject* parent);
    virtual void respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard);
};

#endif // CHARACTERBUSHIDOBILL_H
