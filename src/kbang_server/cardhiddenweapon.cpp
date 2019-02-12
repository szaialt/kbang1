#include "cardhiddenweapon.h"
#include "player.h"
#include "gametable.h"
#include "gamecycle.h"
#include "gameexceptions.h"
#include "characterbase.h"

CardHiddenWeapon::CardHiddenWeapon(Game *game, int id, CardSuit suit, CardRank rank):
        PlayingCard(game, id, CARD_HIDDEN_WEAPON, suit, rank)
{
}

CardHiddenWeapon::~CardHiddenWeapon()
{
}

CardColor CardHiddenWeapon::color() const{
    return COLOR_BLUE;
}

void CardHiddenWeapon::play()
{
    playAsBlueCard();
}


void CardHiddenWeapon::registerPlayer(Player* player)
{
    player->setWeaponNumber(2);
}

void CardHiddenWeapon::unregisterPlayer(Player* player)
{
    player->setWeaponNumber(1);
}


