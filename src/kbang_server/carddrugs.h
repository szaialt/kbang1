#ifndef CARDDRUGS_H
#define CARDDRUGS_H

#include "playingcard.h"
#include "checkdeckresulthandler.h"

class CardDrugs : public PlayingCard {
public:
  CardDrugs(Game *game, int id, CardSuit suit, CardRank rank);
  virtual CardColor color() const;
  virtual void play();
  virtual void registerPlayer(Player* player);
  virtual void unregisterPlayer(Player* player);
}; 

#endif // CARDDRUGS_H
