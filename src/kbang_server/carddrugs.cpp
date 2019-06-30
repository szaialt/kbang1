#include "carddrugs.h"
#include "gamecycle.h"
#include "gameexceptions.h"
#include "gametable.h"
#include "game.h"
#include "player.h"
#include "cardbang.h"

CardDrugs::CardDrugs(Game *game, int id, CardSuit suit, CardRank rank):
        PlayingCard(game, id, CARD_DRUGS, suit, rank)
{

}

CardColor CardDrugs::color() const {
    return COLOR_POSITIVE_GREY;
}

void CardDrugs::play()
{
    assertInHand();
    gameCycle()->assertTurn();
    playAsBlueCard();
    
}    

void CardDrugs::registerPlayer(Player* player)
{
     player->modifyUnlimitedBangs(1); // unlimitedBangs = 1
}

void CardDrugs::unregisterPlayer(Player* player)
{
    player->modifyUnlimitedBangs(-1); // unlimitedBangs = 0
}


