#include "characterdjango.h"
#include "gametable.h"
#include "gamecycle.h"
#include "player.h"
#include "cardmultishoot.h"
#include "gameexceptions.h"

CharacterDjango::CharacterDjango(QObject *parent):
        CharacterBase(parent, CHARACTER_DJANGO)
{
    m_canUseAbility = true;
    
}

void CharacterDjango::useAbility(QList<PlayingCard*> cards)
{
    if (cards.empty()) throw BadUsageException();
    if (cards.size() == 1) throw BadUsageException();
    PlayingCard* targetCard = cards.at(0);
    if (targetCard == 0) throw BadUsageException();
    if (targetCard->owner() != mp_player) throw BadUsageException();
    if (targetCard->pocket() != POCKET_HAND) throw BadUsageException();
    PlayingCard* targetCard2 = cards.at(1);
    if (targetCard2 == 0) throw BadUsageException();
    if (targetCard2->owner() != mp_player) throw BadUsageException();
    if (targetCard2->pocket() != POCKET_HAND) throw BadUsageException();
     mp_gatling = new CardMultiShoot(mp_player->game(), -1, CardMultiShoot::Gatling, SUIT_INVALID, 5);
     mp_gatling->setVirtual(mp_player, POCKET_HAND);
    //Why cann't he fire the gatling?
     mp_gatling->play();
    gameTable().cancelCard(targetCard);
    gameTable().cancelCard(targetCard2);
    m_canUseAbility = false;
    notifyAbilityUse();
     
}

void CharacterDjango::resetAbility(){
    m_canUseAbility = true;
}
