#ifndef CARDINFLAMMATORYBOTTLE_H
#define CARDINFLAMMATORYBOTTLE_H

#include "playingcard.h"
#include "checkdeckresulthandler.h"

class CardFlameBottle : public PlayingCard {
public:
  CardFlameBottle(Game *game, int id, CardSuit suit, CardRank rank);
  virtual CardColor color() const;
  virtual void play();
  virtual void play(Player* targetPlayer);
}; 

#endif // CARDINFLAMMATORYBOTTLE_H
