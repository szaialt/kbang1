#ifndef CHARACTERWHITEWOLF_H
#define CHARACTERWHITEWOLF_H

#include "characterbase.h"

class CharacterWhiteWolf : public CharacterBase
{
Q_OBJECT
public:
    enum Type {
        WhiteWolf,
        FlintDixon
    };
    CharacterWhiteWolf(QObject* parent, Type type);
    virtual void useAbility(QList<PlayingCard*> cards, Player* targetPlayer);
private:
    Type m_type;
};

#endif // CHARACTERWHITEWOLF_H
