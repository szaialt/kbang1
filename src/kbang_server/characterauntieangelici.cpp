#include "characterauntieangelici.h"
#include "player.h"
#include "gametable.h"
#include "playingcard.h"
#include "cardbeer.h"

CharacterAuntieAngelici::CharacterAuntieAngelici(QObject* parent):
        CharacterBase(parent, CHARACTER_AUNTIE_ANGELICI)
       
{
}

int CharacterAuntieAngelici::maxLifePoints() const {
    return 5;
}

void CharacterAuntieAngelici::useAbility(QList<PlayingCard*> cards){
    if (cards.empty()){
        throw BadCardException();
    }
    else {
            PlayingCard* targetCard = cards.at(0);
            if (targetCard->owner() != mp_player || targetCard->pocket() != POCKET_HAND)
                throw BadCardException();
            PlayingCard* saloon = new CardBeer(mp_player->game(), -1, CardBeer::Saloon, targetCard->suit(), targetCard->rank());
            saloon->setVirtual(targetCard);
            saloon->play();
            notifyAbilityUse();
        }
    
} 
