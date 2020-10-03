#ifndef CHARACTERFELIPEDELGADO_H
#define CHARACTERFELIPEDELGADO_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterFelipeDelgado : public CharacterBase
{
Q_OBJECT
public:
    CharacterFelipeDelgado(QObject* parent);
    virtual void useAbility(QList<PlayingCard*> cards);
    virtual void resetAbility();
protected: 
    int m_usedAbility;
};

#endif // CHARACTERFELIPEDELGADO_H
