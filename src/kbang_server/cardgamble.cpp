#include "cardgamble.h"
#include "gamecycle.h"
#include "gameexceptions.h"
#include "gametable.h"
#include "game.h"
#include "player.h"

CardGamble::CardGamble(Game *game, int id, CardSuit suit, CardRank rank, int PredrawCheck):
        PlayingCard(game, id, CARD_GAMBLE, suit, rank)
{
    m_PredrawCheck = PredrawCheck;
}
 
CardGamble::~CardGamble() 
{
}

CardColor CardGamble::color() const {
    return COLOR_BLUE;
}

void CardGamble::play()
{
    if (gameCycle()->isDraw()) {
        assertOnTable();
        owner()->predrawCheck(m_PredrawCheck);
        gameCycle()->checkDeck(owner(), this, *CardGamble::check, this);
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
        gameCycle()->assertTurn();
        assertInHand();
        if (owner()->hasIdenticalCardOnTable(this)) {
            throw TwoSameOnTableException();
        }
        gameTable()->playerPlayCardOnTable(this);
    }
}

void CardGamble::checkResult(bool result)
{
    if (result) { // bad luck
        gameTable()->passTableCard(this, game()->nextPlayer(owner()));
        gameCycle()->noDraw();
    } else { //dynamite goes off
        Player* player = owner();
        gameTable()->playerDiscardCard(this);
        qDebug() << "Gamble goes off";
        gameTable()->playerDrawFromDeck(player, 1);
        qDebug() << "Gamble went off";
    }
}


void CardGamble::registerPlayer(Player* player)
{
   player->registerPredrawCheck(m_PredrawCheck);
}

void CardGamble::unregisterPlayer(Player* player)
{
   player->unregisterPredrawCheck(m_PredrawCheck);
}


bool CardGamble::check(PlayingCard* card)
{
    return  (card->suit() != SUIT_CLUBS);
}
