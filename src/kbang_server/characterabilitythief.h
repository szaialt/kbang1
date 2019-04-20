#ifndef CHARACTERABILITYTHIEF_H
#define CHARACTERABILITYTHIEF_H

#include "characterbase.h"

class CharacterAbilityThief : public CharacterBase
{
Q_OBJECT
public:
    enum Type {
        JimScarecrow,
        LadyBourbon
    };
    
    CharacterAbilityThief(QObject *parent, Type);
    virtual void useAbility(QList<PlayingCard*> cards, Player* targetPlayer);
    private:
        Type m_type;

};

#endif // CHARACTERABILITYTHIEF_H
