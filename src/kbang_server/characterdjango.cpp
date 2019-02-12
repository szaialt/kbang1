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
    qDebug() << "Django using his ability 1";
    if (cards.empty()) throw BadUsageException();
    qDebug() << "Django using his ability 2";
    if (cards.size() == 1) throw BadUsageException();
    qDebug() << "Django using his ability 3";
    PlayingCard* targetCard = cards.at(0);
    qDebug() << "Django using his ability 4";
    if (targetCard == 0) throw BadUsageException();
    qDebug() << "Django using his ability 5";
    if (targetCard->owner() != mp_player) throw BadUsageException();
    qDebug() << "Django using his ability 6";
    if (targetCard->pocket() != POCKET_HAND) throw BadUsageException();
    qDebug() << "Django using his ability 7";
    PlayingCard* targetCard2 = cards.at(1);
    qDebug() << "Django using his ability 8";
    if (targetCard2 == 0) throw BadUsageException();
    qDebug() << "Django using his ability 9";
    if (targetCard2->owner() != mp_player) throw BadUsageException();
    qDebug() << "Django using his ability 10";
    if (targetCard2->pocket() != POCKET_HAND) throw BadUsageException();
    qDebug() << "Django using his ability 11";
     mp_gatling = new CardMultiShoot(mp_player->game(), -1, CardMultiShoot::Gatling, SUIT_INVALID, 5);
//    CardMultiShoot* gatling = new CardMultiShoot(mp_player->game(), -1, CardMultiShoot::Gatling, SUIT_INVALID, 5);
    qDebug() << "Django using his ability 12";
     mp_gatling->setVirtual(mp_player, POCKET_HAND);
//    gatling->setVirtual(mp_player, POCKET_HAND);
    qDebug() << "Django using his ability 13";
    //Why cann't he fire the gatling?
     mp_gatling->play();
//    gatling->play();
    qDebug() << "Django using his ability 14";
    gameTable().cancelCard(targetCard);
    qDebug() << "Django using his ability 15";
    gameTable().cancelCard(targetCard2);
    qDebug() << "Django using his ability 16";
    m_canUseAbility = false;
    qDebug() << "Django using his ability 17";
    notifyAbilityUse();
    qDebug() << "Django using his ability 18";
     
}

void CharacterDjango::resetAbility(){
    m_canUseAbility = true;
}
