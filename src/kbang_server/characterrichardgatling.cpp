#include "characterrichardgatling.h"
#include "playingcard.h"
#include "cardmultishoot.h"

CharacterRichardGatling::CharacterRichardGatling(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_RICHARD_GATLING);
  m_times = 0;
}

 void CharacterRichardGatling::useAbility(QList<PlayingCard*> cards){
     if (m_times < 1){
    if (cards.size() < 2){
        throw BadCardException();
    }
    PlayingCard* targetCard = cards.at(0);
    if (targetCard->owner() != mp_player){
        throw BadCardException();
    }
    if (targetCard->type() != CARD_MISSED){
        throw BadCardException();
    }
    PlayingCard* targetCard2 = cards.at(1);
    if (targetCard2->owner() != mp_player){
        throw BadCardException();
    }
    CardMultiShoot* gatling = new CardMultiShoot(mp_player->game(), 0, CardMultiShoot::Gatling, targetCard->suit(), targetCard->rank());
    gatling->setVirtual(targetCard);
    gatling->play();
    gameTable().playerDiscardCard(targetCard2);
    m_times++;
    notifyAbilityUse();
     }
}

void CharacterRichardGatling::resetAbility(){
    m_times = 0;
}
