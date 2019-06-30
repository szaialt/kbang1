#include "gametable.h"
#include "cardshock.h"

CardShock::CardShock(Game* game, int id, CardSuit cardSuit, CardRank cardRank):
        PlayingCard(game, id, CARD_SHOCK, cardSuit, cardRank)
{
}

CardColor CardShock::color() const {
    return COLOR_NEGATIVE_GREY;
}

void CardShock::play(Player* targetPlayer)
{
    gameCycle()->assertTurn();
    assertInHand();
    if (!(game()->gameInfo().ourFlag())){
       if (targetPlayer->hasIdenticalCardOnTable(this)){
         throw TwoSameOnTableException();
       }
       else {
         gameTable()->playerPlayCardOnTable(this, targetPlayer);
      }
    } 
    
    else {
        if (targetPlayer->hasIdenticalCardOnTable(this)){
          foreach(PlayingCard* card2, targetPlayer->table()) {
            if (card2 == 0)
              continue;
            if (card2->type() == this->type()){
              if (card2->pocket() == POCKET_GRAVEYARD) {
                card2->setPocket(POCKET_TABLE);
                card2->setOwner(owner());
              }
              gameTable()->playerDiscardCard(card2);
            }
          }
        }
      gameTable()->playerPlayCardOnTable(this, targetPlayer);
    }
}
 

