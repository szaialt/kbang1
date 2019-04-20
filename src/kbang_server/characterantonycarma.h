#ifndef CHARACTERANTONYCARMA_H
#define CHARACTERANTONYCARMA_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"
#include "reactionhandler.h"

class CharacterAntonyCarma : public CharacterBase
{
Q_OBJECT
public: 
    CharacterAntonyCarma(QObject* parent);
    virtual void respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard);
private:
    bool check(PlayingCard* card);
};

#endif // CHARACTERANTONYCARMA_H
