#ifndef CARDPERSUASION_H
#define CARDPERSUASION_H

#include "playingcard.h"

class Player;

class CardPersuasion : public PlayingCard
{
Q_OBJECT;
public:

    CardPersuasion(Game *game, int id, CardSuit suit, CardRank rank);
    ~CardPersuasion();

    virtual void play();
    virtual void play(PlayingCard* targetCard, Player* targetPlayer);
    virtual CardColor color() const;

    void resetTimes();
private:
    int m_times;
};

#endif // CARDPERSUASION_H
