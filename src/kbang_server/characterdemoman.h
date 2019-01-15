#ifndef CHARACTERDEMOMAN_H
#define CHARACTERDEMOMAN_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterDemoman : public CharacterBase
{
Q_OBJECT
public:
    CharacterDemoman(QObject* parent);
    virtual void playCard(PlayingCard* card, Player* targetPlayer);
};

#endif // CHARACTERDEMOMAN_H
