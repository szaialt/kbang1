#ifndef CARDWEAKNESS_H
#define CARDWEAKNESS_H

#include "playingcard.h"

class CardWeakness : public PlayingCard {
    Q_OBJECT
public:
    CardWeakness(Game* game, int id, CardSuit cardSuit, CardRank cardRank);
    CardColor color() const;
    void play(Player* targetPlayer);
    void increasePlayedCards();
    void vulnerate();
private:
    int m_playedCards;
}; 

#endif // CARDWEAKNESS_H
