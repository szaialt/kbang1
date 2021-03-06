#include "charactercrazyhorse.h"
#include "player.h"
#include "gamecycle.h"
#include "cardmultishoot.h"
#include "gametable.h"

CharacterCrazyHorse::CharacterCrazyHorse(QObject* parent):
        CharacterBase(parent, CHARACTER_CRAZY_HORSE)
       
{
}

void CharacterCrazyHorse::useAbility(QList<PlayingCard*> cards){
    if (cards.empty()){
        throw BadCardException();
    }
    if (cards.size() < 2){
        throw BadCardException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->owner() != mp_player) throw BadCardException();
        if (targetCard->pocket() != POCKET_HAND) throw BadCardException();
        if (targetCard->type() != CARD_BANG) throw BadCardException();
        PlayingCard* targetCard2 = cards.at(1);
        if (targetCard2->owner() != mp_player) throw BadCardException();
        if (targetCard2->pocket() != POCKET_HAND) throw BadCardException();
        gameTable().playerDiscardCard(targetCard2);
        PlayingCard* hit = new CardMultiShoot(mp_player->game(), -1, CardMultiShoot::Indians, targetCard->suit(), targetCard->rank());
        hit->setVirtual(targetCard);
        hit->play();
        notifyAbilityUse();
    }
} 

