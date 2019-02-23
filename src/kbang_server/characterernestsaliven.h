#ifndef CHARACTERERNESTSALIVEN_H
#define CHARACTERERNESTSALIVEN_H

#include "characterbase.h"

class CharacterErnestSaliven : public CharacterBase
{
Q_OBJECT
public:
    CharacterErnestSaliven(QObject* parent);
    virtual void useAbility(QList<PlayingCard*> cards);
void resetAbility();
private:
    bool m_canUseAbility;
};

#endif // CHARACTERERNESTSALIVEN_H
