#ifndef CHARACTERSTONEWALLJACKSON_H
#define CHARACTERSTONEWALLJACKSON_H

#include "characterbase.h"

class CharacterStonewallJackson : public CharacterBase
{
Q_OBJECT
public:
    CharacterStonewallJackson(QObject *parent);
    virtual void playCard(PlayingCard* card, Player* targetPlayer);
    virtual void respondCard(ReactionHandler*, PlayingCard* targetCard);
private:
    bool check(PlayingCard* card);
};

#endif // CHARACTERSTONEWALLJACKSON_H
