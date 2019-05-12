#include "cardthunder.h"
#include "gameexceptions.h"
#include "player.h"
#include "gametable.h"
#include "gamecycle.h"
#include "characterbase.h"

CardThunder::CardThunder(Game *game, int id, CardSuit suit, CardRank rank):
        PlayingCard(game, id, CARD_THUNDER, suit, rank)
        
{
}

CardThunder::~CardThunder()
{
}

void CardThunder::play(PlayingCard* targetCard, Player* targetPlayer){
     if (targetCard == 0) throw BadUsageException();
     gameTable()->playerPlayCard(this);
     gameTable()->playerStealCard(targetPlayer, targetCard);
}

