#ifndef CHARACTERTEDREVENGE_H
#define CHARACTERTEDREVENGE_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"
#include "reactionhandler.h"

class CharacterTedRevenge : public CharacterBase
{
Q_OBJECT
public:
    CharacterTedRevenge(QObject* parent);
    virtual void respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard);
    void resetAbility();
private:
    int m_times;
};

#endif // CHARACTERTEDREVENGE_H
