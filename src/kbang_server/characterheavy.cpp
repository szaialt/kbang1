#include "characterheavy.h"
#include "playingcard.h"
#include "cardbang.h"

CharacterHeavy::CharacterHeavy(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_HEAVY);
}

int CharacterHeavy::maxLifePoints() const{
    return 5;
}

void CharacterHeavy::CharacterHeavy::useAbility(QList<PlayingCard*> cards, Player* targetPlayer){
    if (cards.empty()){
        throw BadCardException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->owner() != mp_player) throw BadCardException();
        if (!targetCard->hasBangSymbol()) throw BadCardException();
        if ((targetPlayer == mp_player->game()->nextPlayer(mp_player)) ||
            (targetPlayer == mp_player->game()->previousPlayer(mp_player))
        ){
            PlayingCard* hit = new CardBang(mp_player->game(), -1, CardBang::Heavy, targetCard->suit(), targetCard->rank());
            hit->setVirtual(targetCard);
            hit->play(targetPlayer);
        }
    }
}

