#include "characterroostercogburn.h"
#include "cardbarrel.h"
#include "player.h"
#include "gamecycle.h"

CharacterRoosterCogburn::CharacterRoosterCogburn(QObject* parent):
        CharacterBase(parent, CHARACTER_ROOSTER_COGBURN),
        mp_hiddenweapon(0)
{
}

void CharacterRoosterCogburn::setPlayer(Player* player)
{
    player->setWeaponNumber(2);
}

