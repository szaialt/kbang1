#include "carddynamite.h"
#include "gamecycle.h"
#include "gameexceptions.h"
#include "gametable.h"
#include "game.h"
#include "player.h"

CardDynamite::CardDynamite(Game *game, int id, CardSuit suit, CardRank rank, int PredrawCheck):
        PlayingCard(game, id, CARD_DYNAMITE, suit, rank)
{
    m_PredrawCheck = PredrawCheck;
}
 
CardDynamite::~CardDynamite() 
{
}

CardColor CardDynamite::color() const {
    if (game()->gameInfo().ourFlag())
        return COLOR_DYNAMITE;
    return COLOR_BLUE;
}

void CardDynamite::play()
{
    if (gameCycle()->isDraw()) {
        assertOnTable();
        if (!(game()->gameInfo().stackingDynamiteFlag())){
            owner()->predrawCheck(m_PredrawCheck);
          gameCycle()->checkDeck(owner(), this, *CardDynamite::checkDynamite, this);
            if ((owner()) && owner()->hasIdenticalCardOnTable(this)) {
              foreach(PlayingCard* card2, owner()->table()) {
                if (card2 == 0){
                  continue;
                }
                if (card2 == this){
                  continue;
                }
                if (card2->type() == this->type()){
                  gameTable()->passTableCard(card2, game()->nextPlayer(owner()));
             }
          }
        }
      }
      else {
          owner()->predrawCheck(m_PredrawCheck);
          gameCycle()->checkDeck(owner(), this, *CardDynamite::checkDynamite, this);
       }
       return;
    } 
    else {
        gameCycle()->assertTurn();
        assertInHand();
        //Double dynamite
        if (!(game()->gameInfo().stackingDynamiteFlag())){
          if (owner()->hasIdenticalCardOnTable(this)) {
            throw TwoSameOnTableException();
          }
        }
        gameTable()->playerPlayCardOnTable(this);
    }
}

void CardDynamite::checkResult(bool result)
{
    if (result) { // luck
        gameTable()->passTableCard(this, game()->nextPlayer(owner()));
    } else { //dynamite goes off
        Player* player = owner();
        gameTable()->playerDiscardCard(this);
        player->modifyLifePoints(-3, 0);
    }
}


void CardDynamite::registerPlayer(Player* player)
{
   player->registerPredrawCheck(m_PredrawCheck);
}

void CardDynamite::unregisterPlayer(Player* player)
{
   player->unregisterPredrawCheck(m_PredrawCheck);
}


bool CardDynamite::checkDynamite(PlayingCard* card)
{
    return  (card->suit() != SUIT_SPADES || card->rank() > 9 || card->rank() < 2);
}
