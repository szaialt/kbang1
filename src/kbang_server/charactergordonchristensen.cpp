#include "charactergordonchristensen.h"
#include "player.h"
#include "carddrawcards.h"

CharacterGordonChristensen::CharacterGordonChristensen(QObject* parent):
        CharacterBase(parent, CHARACTER_GORDON_CHRISTENSEN)
       
{
    m_times = 0;
}

void CharacterGordonChristensen::useAbility(QList<PlayingCard*> cards){
    if (cards.empty()){
        throw BadCardException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->owner() != mp_player) throw BadCardException();
        if (targetCard->pocket() != POCKET_HAND) throw BadCardException();
        if (targetCard->color() != COLOR_GREEN) throw BadCardException();
        if (m_times < 2){
            PlayingCard* draw = new CardDrawCards(mp_player->game(), -1, CardDrawCards::Diligenza, SUIT_INVALID, 5);
            draw->setVirtual(targetCard);
            draw->play();
            m_times++;
            notifyAbilityUse();
        }
    }
} 

void CharacterGordonChristensen::resetAbility(){
    m_times = 0;
}
