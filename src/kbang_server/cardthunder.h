#ifndef CARDTHUNDER_H
#define CARDTHUNDER_H

#include "playingcard.h"

class Player;

class CardThunder : public PlayingCard
{
Q_OBJECT;
public:

    CardThunder(Game *game, int id, CardSuit suit, CardRank rank);
    ~CardThunder();

    virtual void play(PlayingCard* targetCard, Player* targetPlayer);

};

#endif // CARDTHUNDER_H
