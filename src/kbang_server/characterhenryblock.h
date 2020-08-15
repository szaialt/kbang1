#ifndef CHARACTERHENRYBLOCK_H
#define CHARACTERHENRYBLOCK_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterHenryBlock : public CharacterBase
{
Q_OBJECT
public:
    CharacterHenryBlock(QObject* parent);
    virtual void setPlayer(Player* player);
public slots: 
    virtual void useAbility(Player* player1, PlayingCard* card, Player* targetPlayer);
    virtual void useAbility(Player* player1, PlayingCard* card, PlayingCard* targetCard, Player* targetPlayer);
    virtual void useAbility(Player* player1, PlayingCard* card, PlayingCard* targetCard);
    virtual void useAbility(Player* player1, PlayingCard* card, QList<PlayingCard*> targetCards);
    virtual void useAbility(Player* player1, PlayingCard* card, QList<PublicPlayerView*> targetPlayers);
    
protected:
    void hit(Player* targetPlayer);
    bool isCardTaker(PlayingCard* card);
};

#endif // CHARACTERHENRYBLOCK_H
