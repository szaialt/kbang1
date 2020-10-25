#ifndef CHARACTERTONYARMED_H
#define CHARACTERTONYARMED_H

#include "characterbase.h"

class CharacterTonyArmed : public CharacterBase
{
Q_OBJECT
public:
    CharacterTonyArmed(QObject *parent);
    virtual void useAbility(QList<PlayingCard*> cards, Player* targetPlayer);
protected: 
    PlayingCard* mp_hit;
};

#endif // CHARACTERTONYARMED_H
