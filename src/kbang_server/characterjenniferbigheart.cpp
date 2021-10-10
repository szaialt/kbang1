#include "characterjenniferbigheart.h"
#include "player.h"
#include "gamecycle.h"
#include "cardtaker.h"

CharacterJenniferBigHeart::CharacterJenniferBigHeart(QObject* parent):
        CharacterBase(parent, CHARACTER_JENNIFER_BIG_HEART)
       
{
}

void CharacterJenniferBigHeart::useAbility(QList<PlayingCard*> cards, Player* targetPlayer){
    if (cards.empty()){
        throw BadUsageException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->owner() != mp_player)
            throw BadUsageException();
        if (targetCard->pocket() != POCKET_HAND)
            throw BadUsageException();
        CardTaker* catbalou = new CardTaker(mp_player->game(), 0, CardTaker::CatBalou, targetCard->suit(), targetCard->rank());
        catbalou->setVirtual(targetCard);
        catbalou->play(targetPlayer);
        notifyAbilityUse();
        
    }
} 
