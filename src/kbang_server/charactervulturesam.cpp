#include "charactervulturesam.h"
#include "player.h"
#include "game.h"
#include "gametable.h"


CharacterVultureSam::CharacterVultureSam(QObject* parent):
        CharacterBase(parent, CHARACTER_VULTURE_SAM)
{
}


void CharacterVultureSam::setPlayer(Player* player)
{
    CharacterBase::setPlayer(player);
    player->game()->getPlayerReaper()->registerVulture(this);
} 

void CharacterVultureSam::playerDied()
{
    mp_player->game()->getPlayerReaper()->unregisterVulture(this);
}

void CharacterVultureSam::cleanUpCards(Player* corpse)
{
    //qDebug() << "VultureSam::Cleaning up cards in hand";
    //qDebug() << "VultureSam::Size of hand is " << corpse->handSize();
    notifyAbilityUse();
    foreach(PlayingCard* card, corpse->hand()){
        mp_player->game()->gameTable().playerStealCard(mp_player, card);
    }
    //qDebug() << "VultureSam::Cleaning up cards on table";
    foreach(PlayingCard* card, corpse->table()){
        mp_player->game()->gameTable().playerStealCard(mp_player, card);
    }
    //qDebug() << "VultureSam::End";
}
