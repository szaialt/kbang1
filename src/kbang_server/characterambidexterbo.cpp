#include "characterambidexterbo.h"
#include "player.h"
#include "playingcard.h"
#include "cardbang.h"

CharacterAmbidexterBo::CharacterAmbidexterBo(QObject* parent):
        CharacterBase(parent, CHARACTER_UNKNOWN)
{
        setCharacterType(CHARACTER_AMBIDEXTER_BO);
        mp_targetedPlayer = mp_player;
 
}

void CharacterAmbidexterBo::setPlayer(Player* player)
{
    CharacterBase::setPlayer(player);
        player->setWeaponNumber(2);
}

Player* CharacterAmbidexterBo::targetedPlayer(){
    return mp_targetedPlayer;
}
    
void CharacterAmbidexterBo::setTargetedPlayer(Player* player){
    mp_targetedPlayer = player;
}

