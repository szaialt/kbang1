#include "characteroscarrodriguez.h"
#include "gametable.h"
#include "gamecycle.h"
#include "player.h"
#include "gameexceptions.h"

CharacterOscarRodriguez::CharacterOscarRodriguez(QObject *parent):
        CharacterBase(parent, CHARACTER_OSCAR_RODRIGUEZ)
{
}

void CharacterOscarRodriguez::useAbility(Player* targetPlayer)
{
    mp_targetPlayer = targetPlayer;
    mp_player->modifyLifePoints(-2, 0);
    mp_targetPlayer->modifyLifePoints(1, 0);
}
