#ifndef CARDMUSTANG_H
#define CARDMUSTANG_H

#include "playingcard.h"

class Player;

class CardHorse : public PlayingCard
{
Q_OBJECT;
public:
    enum HorseType {
        Mustang,
        Appaloosa
    };

    CardHorse(Game *game, int id, HorseType, CardSuit, CardRank);
    ~CardHorse();

    virtual void play();
    virtual CardColor color() const;
    virtual void registerPlayer(Player* player);
    virtual void unregisterPlayer(Player* player);

private:
    HorseType m_horseType;
};

#endif // CARDMUSTANG_H
