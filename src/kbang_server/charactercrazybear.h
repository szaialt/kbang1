#ifndef CHARACTERCRAZYBEAR_H
#define CHARACTERCRAZYBEAR_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterCrazyBear : public CharacterBase
{
Q_OBJECT
public:
    CharacterCrazyBear(QObject* parent);
    virtual void playCard(PlayingCard* card, Player* targetPlayer);
    int injury();
private:
    int m_injury;
};

#endif // CHARACTERCRAZYBEAR_H
