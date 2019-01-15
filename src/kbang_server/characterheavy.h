#ifndef CHARACTERHEAVY_H
#define CHARACTERHEAVY_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"
#include "playingcard.h"

class CharacterHeavy : public CharacterBase
{
Q_OBJECT
public:
    CharacterHeavy(QObject* parent);
    virtual int maxLifePoints() const;
    virtual void useAbility(QList<PlayingCard*> cards, Player* targetPlayer);
protected:
    bool hasBangSymbol(PlayingCard* card);
    
};

#endif // CHARACTERHEAVY_H
