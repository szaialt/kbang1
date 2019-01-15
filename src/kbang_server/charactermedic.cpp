#include "charactermedic.h"
#include "player.h"
#include "gamecycle.h"
#include "cardteamfortressbang.h"

CharacterMedic::CharacterMedic(QObject* parent):
        CharacterBase(parent, CHARACTER_MEDIC)
       
{
}

void CharacterMedic::useAbility(QList<PlayingCard*> cards, Player* targetPlayer){
    if (cards.empty()){
        throw BadCardException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->type() == CARD_BANG){
            CardBang* healing = new CardTeamFortressBang(mp_player->game(), 0, CardBang::HealingBang, targetCard->suit(), targetCard->rank());
            healing->setVirtual(targetCard);
            healing->play(targetPlayer);
            notifyAbilityUse();
        }
        else throw BadUsageException();
        
    }
} 
