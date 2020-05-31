#ifndef CHARACTERTURDFERGUSON_H
#define CHARACTERTURDFERGUSON_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"
#include "reactionhandler.h"

class CharacterTurdFerguson : public CharacterBase
{
Q_OBJECT
public:
    CharacterTurdFerguson(QObject* parent);
    virtual void respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard);
    void resetAbility();
protected:
    bool m_used;
};

#endif // CHARACTERTURDFERGUSON_H
