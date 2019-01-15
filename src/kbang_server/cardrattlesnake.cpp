#include "cardrattlesnake.h"
#include "gamecycle.h"
#include "gameexceptions.h"
#include "gametable.h"
#include "game.h"
#include "player.h"

CardRattlesnake::CardRattlesnake(Game *game, int id, CardSuit suit, CardRank rank, int PredrawCheck):
        PlayingCard(game, id, CARD_RATTLESNAKE, suit, rank)
{
    m_PredrawCheck = PredrawCheck;
}

CardColor CardRattlesnake::color() const {
    return COLOR_BLUE;
}

void CardRattlesnake::play()
{
    //gameCycle()->assertDraw();
    assertOnTable();
    owner()->predrawCheck(m_PredrawCheck);
    gameCycle()->checkDeck(owner(), this, *CardRattlesnake::check, this);
}

void CardRattlesnake::play(Player* targetPlayer)
{
    gameCycle()->assertTurn();
    assertInHand();
    if (targetPlayer->hasIdenticalCardOnTable(this)) {
        throw TwoSameOnTableException();
    }
    gameTable()->playerPlayCardOnTable(this, targetPlayer);
}

void CardRattlesnake::checkResult(bool result)
{
    if (!result) { //rattlesnake goes off
        Player* player = owner();
        player->modifyLifePoints(-1, 0);
    }
}

void CardRattlesnake::registerPlayer(Player* player)
{
   player->registerPredrawCheck(m_PredrawCheck);
}

void CardRattlesnake::unregisterPlayer(Player* player)
{
   player->unregisterPredrawCheck(m_PredrawCheck);
}


bool CardRattlesnake::check(PlayingCard* card)
{
    return  (card->suit() != SUIT_SPADES);
}
