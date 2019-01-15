#ifndef CARDRATTLESNAKE_H
#define CARDRATTLESNAKE_H

#include "playingcard.h"
#include "checkdeckresulthandler.h"

class CardRattlesnake : public PlayingCard, public CheckDeckResultHandler
{
public:
  CardRattlesnake(Game *game, int id, CardSuit suit, CardRank rank, int PredrawCheck);
  virtual CardColor color() const;
  virtual void play();
  virtual void play(Player* targetPlayer);
  virtual void checkResult(bool result);
  virtual void registerPlayer(Player* player);
  virtual void unregisterPlayer(Player* player);
  static bool check(PlayingCard* card);
};

#endif // CARDRATTLESNAKE_H
