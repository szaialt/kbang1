#include "cardpersuasion.h"
#include "gameexceptions.h"
#include "player.h"
#include "gametable.h"
#include "gamecycle.h"
#include "characterbase.h"

CardPersuasion::CardPersuasion(Game *game, int id, CardSuit suit, CardRank rank):
        PlayingCard(game, id, CARD_PERSUASION, suit, rank),
        m_times(0)
        
{
}

CardPersuasion::~CardPersuasion()
{
}

void CardPersuasion::play()
{
    playAsBlueCard();
}

void CardPersuasion::play(PlayingCard* targetCard, Player* targetPlayer){
     if (m_times >= 2){
         return;
     }
     Player* owner1  = owner();
     if (targetCard == 0) throw BadUsageException();
     if (targetCard->owner() != owner1) throw BadUsageException();
     if (pocket() != POCKET_TABLE) throw BadUsageException();
     if (targetCard->pocket() != POCKET_HAND) throw BadUsageException();
     PlayingCard* targetCard2 = targetPlayer->getRandomCardFromHand();
     if (targetCard2 == 0) return;
     gameTable()->playerStealCard(owner1, targetCard2);
     gameTable()->playerStealCard(targetPlayer, targetCard);
     m_times++;
}

CardColor CardPersuasion::color() const {
    return COLOR_BLUE;
}

void CardPersuasion::resetTimes(){
    m_times = 0;
}
