#ifndef CHARACTERSOLDIER_H
#define CHARACTERSOLDIER_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"
#include "reactionhandler.h"

class CharacterSoldier : public CharacterBase
{
Q_OBJECT
public: 
    CharacterSoldier(QObject* parent);
    virtual void respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard);
};

#endif // CHARACTERSOLDIER_H
