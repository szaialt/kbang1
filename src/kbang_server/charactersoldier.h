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
    enum Type {
        Soldier,
        LlaneroSolitario,
        SergeantOReilly
    };
    CharacterSoldier(QObject* parent, Type type);
    virtual void respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard);
private:
    Type m_type;
};

#endif // CHARACTERSOLDIER_H
