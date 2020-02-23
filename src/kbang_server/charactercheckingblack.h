#ifndef CHARACTERCHECKINGBLACK_H
#define CHARACTERCHECKINGBLACK_H

#include "characterbase.h"

class CharacterCheckingBlack : public CharacterBase
{
Q_OBJECT
public:
    enum Type {
        WilliamHarman,
        Clockwork
    };
    CharacterCheckingBlack(QObject *parent, Type type);
    virtual void useAbility();
    virtual void useAbility(Player* targetPlayer);
    void resetAbility();

private:
    Type m_type;
    bool m_used;
    bool check(PlayingCard* card);
};

#endif // CHARACTERCHECKINGBLACK_H
