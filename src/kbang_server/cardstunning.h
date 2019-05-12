#ifndef CARDSTUNNING_H
#define CARDSTUNNING_H

#include "playingcard.h"
#include "checkdeckresulthandler.h"

class CardStunning : public PlayingCard {
public:
  CardStunning(Game *game, int id, CardSuit suit, CardRank rank);
  virtual CardColor color() const;
  virtual void play();
  virtual void play(PlayingCard* targetCard, Player* targetPlayer);
}; 

#endif // CARDSTUNNING_H
