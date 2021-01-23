#ifndef CHARACTERHANKTHEBANK_H
#define CHARACTERHANKTHEBANK_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterHankTheBank  : public CharacterBase
{
Q_OBJECT
public:
    CharacterHankTheBank(QObject* parent);
    virtual void playCard(PlayingCard* card);
    virtual void useAbility(QList<PlayingCard*> cards);
protected:
    bool m_halfLife;
};

#endif // CHARACTERHANKTHEBANK_H
