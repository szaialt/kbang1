#ifndef CHARACTERWYATTEARP_H
#define CHARACTERWYATTEARP_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterWyattEarp : public CharacterBase
{
Q_OBJECT
public:
    enum Type {
        WyattEarp,
        RonRobber
    };
    CharacterWyattEarp(QObject* parent, Type type);
    virtual void useAbility(QList<PlayingCard*> cards, Player* targetPlayer);
private:
    Type m_type;
};

#endif // CHARACTERWYATTEARP_H
