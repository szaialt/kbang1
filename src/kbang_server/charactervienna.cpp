#include "charactervienna.h"
#include "player.h"
#include "gamecycle.h"
#include "cardduel.h"

CharacterVienna::CharacterVienna(QObject* parent):
        CharacterBase(parent, CHARACTER_VIENNA)
       
{
    m_canUseAbility = true;
}

void CharacterVienna::useAbility(QList<PlayingCard*> cards, Player* targetPlayer){
    if (cards.empty()){
        throw BadCardException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->color() == COLOR_BROWN){
            CardDuel* duel = new CardDuel(mp_player->game(), 0, CardDuel::Duel, targetCard->suit(), targetCard->rank());
            duel->setVirtual(targetCard);
            duel->play(targetPlayer);
            notifyAbilityUse();
            m_canUseAbility = false;
        }
        else throw BadUsageException();
        
    }
} 

void CharacterVienna::resetAbility(){
    m_canUseAbility = true;
}
