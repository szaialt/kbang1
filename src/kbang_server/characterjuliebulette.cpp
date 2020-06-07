#include "characterjuliebulette.h"
#include "player.h"
#include "carddrawcards.h"
#include "gametable.h"

CharacterJulieBulette::CharacterJulieBulette(QObject* parent):
        CharacterBase(parent, CHARACTER_JULIE_BULETTE)
       
{
    m_used = false;
}

void CharacterJulieBulette::useAbility(QList<PlayingCard*> cards){
    if (cards.empty()){
        throw BadCardException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->owner() != mp_player) throw BadCardException();
        if (!m_used){
            gameTable().playerDiscardCard(targetCard);
            QList<PlayingCard*> drawedCards = gameTable().playerDrawFromDeck(mp_player, 1, 0);
            notifyAbilityUse();
            if (!(drawedCards.at(0)->suit() == SUIT_DIAMONDS)) m_used = true;
        }
    }
} 

void CharacterJulieBulette::resetAbility(){
    m_used = false;
}
