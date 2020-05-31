#ifndef CHARACTERQUEENANNE_H
#define CHARACTERQUEENANNE_H

#include "characterbase.h"

class CharacterQueenAnne : public CharacterBase
{
Q_OBJECT
public:
    CharacterQueenAnne(QObject* parent);
    virtual void useAbility(QList<PlayingCard*> cards);
};

#endif // CHARACTERQUEENANNE_H
