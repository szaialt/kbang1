#ifndef CHARACTERPATGARRETT_H
#define CHARACTERPATGARRETT_H

#include "characterbase.h"

class CharacterPatGarrett : public CharacterBase
{
Q_OBJECT
public:
    CharacterPatGarrett(QObject *parent);
    virtual void useAbility(QList<PlayingCard*> cards, Player* targetPlayer);
    void resetAbility();
protected:
    bool m_canUseAbility;
};

#endif // CHARACTERPATGARRETT_H
