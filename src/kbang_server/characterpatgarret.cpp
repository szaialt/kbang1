#include "characterpatgarret.h"
#include "player.h"
#include "gamecycle.h"
#include "cardjail.h"

CharacterPatGarrett::CharacterPatGarrett(QObject* parent):
        CharacterBase(parent, CHARACTER_PAT_GARRETT)
       
{
        m_canUseAbility = true;
}

void CharacterPatGarrett::useAbility(QList<PlayingCard*> cards, Player* targetPlayer){
    if (cards.empty()){
        throw BadCardException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->isWeapon()){
            CardJail* jail = new CardJail(mp_player->game(), 0, CardJail::Jail, targetCard->suit(), targetCard->rank(), 8);
            jail->setVirtual(targetCard);
            jail->play(targetPlayer);
            m_canUseAbility = false;
            notifyAbilityUse();
        }
        else throw BadUsageException();
        
    }
} 

void CharacterPatGarrett::resetAbility(){
    m_canUseAbility = true;
}
