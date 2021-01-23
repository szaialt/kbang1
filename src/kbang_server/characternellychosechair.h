#ifndef CHARACTERNELLYCHOSECHAIR_H
#define CHARACTERNELLYCHOSECHAIR_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"
#include "playingcard.h"

class CharacterNellyChoseChair : public CharacterBase
{
Q_OBJECT
public:
        enum Type {
        NellyChoseChair,
        Spy
    };
    CharacterNellyChoseChair(QObject* parent, Type);
    virtual void useAbility(Player* targetPlayer);
    virtual void useAbility(QList<PlayingCard*> cards, Player* targetPlayer);
private:
    Type m_type;
    
};

#endif // CHARACTERNELLYCHOSECHAIR_H
