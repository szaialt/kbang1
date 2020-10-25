#include "charactertonyarmed.h"
#include "player.h"
#include "gametable.h"
#include "cardbang.h"

CharacterTonyArmed::CharacterTonyArmed(QObject* parent):
        CharacterBase(parent, CHARACTER_TONY_ARMED)
       
{
}

void CharacterTonyArmed::useAbility(QList<PlayingCard*> cards, Player* targetPlayer){
    if (cards.empty()){
        throw BadCardException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->owner() != mp_player ){
            throw BadCardException();
        }
        if (targetCard->pocket() != POCKET_HAND){
            throw BadCardException();
        }
       gameTable().playerDiscardCard(targetCard);
       
       mp_hit = new CardBang(mp_player->game(), -1, CardBang::Bang, SUIT_INVALID, 5);
        mp_hit->setVirtual(mp_player, POCKET_HAND);
        mp_hit->play(targetPlayer);
        notifyAbilityUse();
        }
} 
