#ifndef CHARACTERCHARACTERRICHARDGATLING_H
#define CHARACTERCHARACTERRICHARDGATLING_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterRichardGatling  : public CharacterBase
{
Q_OBJECT
public:
    CharacterRichardGatling(QObject* parent);
    virtual void useAbility(QList<PlayingCard*> cards);
    void resetAbility();
protected:
    int m_times;
};

#endif // CHARACTERCHARACTERRICHARDGATLING_H
