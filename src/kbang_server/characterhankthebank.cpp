#include "characterhankthebank.h"
#include "playingcard.h"
#include "gametable.h"

CharacterHankTheBank::CharacterHankTheBank(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_HANK_THE_BANK);
  m_halfLife = false;
}

void CharacterHankTheBank::playCard(PlayingCard* card){
    if (card->pocket() == POCKET_BANK){
       gameTable().playerDrawFromBank(mp_player);  
    }
    else {
        card->play();
    }
}


void CharacterHankTheBank::useAbility(QList<PlayingCard*> cards){
       if (cards.empty()){
        throw BadUsageException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->owner() != mp_player) throw BadUsageException();
        if (targetCard->pocket() != POCKET_HAND){
            BadUsageException();
        }
        if (mp_player->bank().isEmpty()){
          gameTable().playerPlayCardOnBank(targetCard, mp_player);
          notifyAbilityUse();
       }
        else {
            throw BadUsageException();
        }
        
    }
}
