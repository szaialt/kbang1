#include "charactercaptwcaroll.h"
#include "player.h"
#include "gametable.h"
#include "playingcard.h"

CharacterCaptWCaroll::CharacterCaptWCaroll(QObject* parent):
        CharacterBase(parent, CHARACTER_CAPT_W_CAROLL)
       
{
    m_times = 0;
}

void CharacterCaptWCaroll::useAbility(QList<PlayingCard*> cards){
    if (cards.empty()){
        throw BadCardException();
    }
    else {
        
        if (m_times < 1){
            int size = cards.size();
            foreach (PlayingCard* card, cards) {
        if (card->owner() != mp_player ||
            card->pocket() != POCKET_HAND)
            throw BadCardException();
    }
            foreach (PlayingCard* targetCard, cards){
                gameTable().playerDiscardCard(targetCard);
            }
            gameTable().playerDrawFromDeck(mp_player, size, 0);
            m_times++;
            notifyAbilityUse();
        }
    }
} 

void CharacterCaptWCaroll::resetAbility(){
    m_times = 0;
}
