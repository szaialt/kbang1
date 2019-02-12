#include "characterpatgarrett.h"
#include "playingcard.h"
#include "cardjail.h"
#include "characterlist.h"

CharacterPatGarrett::CharacterPatGarrett(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_PAT_GARRETT);
}

void CharacterPatGarrett::useAbility(QList<PlayingCard*> cards, Player* targetPlayer){
    if (cards.empty()){
        throw BadCardException();
    }
    else {
        PlayingCard* card = cards.at(0);
        if (card->owner() != mp_player) throw BadCardException();
        if (!card->isWeapon()) throw BadCardException();
        
        CardJail* jail = new CardJail(mp_player->game(), 0, CardJail::Jail, card->suit(), card->rank(), 10);
        //jail->setOwner(mp_player);
        //jail->setPocket(POCKET_HAND);
        jail->setVirtual(card);
        jail->play(targetPlayer);
        notifyAbilityUse();
    }
}


