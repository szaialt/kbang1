#ifndef CHARACTERJOELJANIS_H
#define CHARACTERJOELJANIS_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"
#include "reactionhandler.h"

class CharacterJoelJanis : public CharacterBase
{
Q_OBJECT
public: 
    CharacterJoelJanis(QObject* parent);
    virtual void playCard(PlayingCard* card);
    virtual void respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard);
};

#endif // CHARACTERJOELJANIS_H
