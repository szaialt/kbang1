#ifndef CHARACTERWILLIAMLONGLEY_H
#define CHARACTERWILLIAMLONGLEY_H

#include "characterbase.h"

class CharacterWilliamLongley : public CharacterBase
{
Q_OBJECT
public:
    CharacterWilliamLongley(QObject *parent);
    virtual int maxLifePoints() const;
    virtual void respondCard(ReactionHandler*, PlayingCard* targetCard);
};

#endif // CHARACTERWILLIAMLONGLEY_H
