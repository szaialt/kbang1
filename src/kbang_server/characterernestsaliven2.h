#ifndef CHARACTERERNESTSALIVEN2_H
#define CHARACTERERNESTSALIVEN2_H

#include "characterbase.h"

class CharacterErnestSaliven2 : public CharacterBase
{
Q_OBJECT
public:
    CharacterErnestSaliven2(QObject* parent);
    virtual void useAbility(QList<PlayingCard*> cards);
void resetAbility();
private:
    bool m_canUseAbility;
};

#endif // CHARACTERERNESTSALIVEN2_H
