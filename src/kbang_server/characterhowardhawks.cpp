#include "characterhowardhawks.h"
#include "player.h"
#include "gamecycle.h"
#include "cardteamfortressbang.h"

CharacterHowardHawks::CharacterHowardHawks(QObject* parent):
        CharacterBase(parent, CHARACTER_HOWARD_HAWKS)
       
{
        m_canUseAbility = true;
}

void CharacterHowardHawks::useAbility(QList<PlayingCard*> cards, Player* targetPlayer){
    if (cards.empty()){
        throw BadCardException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->type() == CARD_BANG){
            CardBang* hawks = new CardBang(mp_player->game(), 0, CardBang::Hawks, targetCard->suit(), targetCard->rank());
            hawks->setVirtual(targetCard);
            hawks->play(targetPlayer);
            m_canUseAbility = false;
            notifyAbilityUse();
        }
        else throw BadUsageException();
        
    }
} 

void CharacterHowardHawks::resetAbility(){
    m_canUseAbility = true;
}
