#ifndef CHARACTERMATTHEWHELL_H
#define CHARACTERMATTHEWHELL_H

#include "characterbase.h"
#include "reactionhandler.h"
#include "gametable.h"
#include "player.h"

class CharacterMatthewHell : public CharacterBase, public ReactionHandler
{
Q_OBJECT
public:
    CharacterMatthewHell(QObject* parent);
    virtual void useAbility(QList<PlayingCard*> cards);
    
    virtual void respondCard(PlayingCard* targetCard);
    virtual ReactionType reactionType() const { return REACTION_KITCARLSON; }
    virtual Player* causedBy() const { return 0; }
};

#endif // CHARACTERMATTHEWHELL_H
