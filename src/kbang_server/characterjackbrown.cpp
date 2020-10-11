#include "characterjackbrown.h"
#include "player.h"
#include "playingcard.h"
#include "gametable.h"

CharacterJackBrown::CharacterJackBrown(QObject* parent):
        CharacterBase(parent, CHARACTER_JACK_BROWN)
    
{
}

void CharacterJackBrown::useAbility(QList<PlayingCard*> cards){
    if (cards.empty()){
        throw BadCardException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->owner() != mp_player) throw BadCardException();
        if (targetCard->pocket() != POCKET_HAND) throw BadCardException();
        if (targetCard->color() != COLOR_BROWN) throw BadCardException();
        targetCard->playAsBlueCard();
        notifyAbilityUse();
    }
} 


