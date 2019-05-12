#include "cardthief.h"
#include "gametable.h"

CardThief::CardThief(Game* game, int id, CardSuit cardSuit, CardRank cardRank):
        PlayingCard(game, id, CARD_THIEF, cardSuit, cardRank)
{
}

void CardThief::play(QList<PlayingCard*> targetCards)
{
    if (targetCards.size() < 2){
        throw BadUsageException();
    }
    if (targetCards.at(0)->owner() == targetCards.at(1)->owner()){
        throw BadUsageException();
    }
    if ((targetCards.at(0)->pocket() != POCKET_TABLE) || (targetCards.at(1)->pocket() != POCKET_TABLE)){
        throw BadUsageException();
    }
    gameTable()->playerPlayCard(this);
    PlayingCard* card1 = targetCards.at(0);
    PlayingCard* card2 = targetCards.at(1);
    Player* owner1 = targetCards.at(0)->owner();
    Player* owner2 = targetCards.at(1)->owner();
    
    gameTable()->playerStealCard(owner1, card2);
    gameTable()->playerStealCard(owner2, card1);
}
