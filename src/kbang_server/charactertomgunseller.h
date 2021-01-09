#ifndef CHARACTERTOMGUNSELLER_H
#define CHARACTERTOMGUNSELLER_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterTomGunSeller : public CharacterBase
{
Q_OBJECT
public:
    CharacterTomGunSeller(QObject* parent);
    virtual void setPlayer(Player* player);
    virtual void playCard(PlayingCard* card, Player* targetPlayer);
    virtual void useAbility(QList<PlayingCard*> cards, Player* targetPlayer);
protected:
    int calculateWeapons();
};

#endif // CHARACTERTOMGUNSELLER_H
