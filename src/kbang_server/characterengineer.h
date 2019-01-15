#ifndef CHARACTERENGINEER_H
#define CHARACTERENGINEER_H

#include "characterbase.h"

class CharacterEngineer : public CharacterBase
{
Q_OBJECT
public:
    CharacterEngineer(QObject *parent);
    virtual void useAbility(QList<PlayingCard*> cards, Player* targetPlayer);
    virtual void respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard);

};

#endif // CHARACTERENGINEER_H
