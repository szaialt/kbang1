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
        if (!hasBangSymbol(targetCard)) throw BadCardException();
        if ((targetPlayer == mp_player->game()->nextPlayer(mp_player)) ||
            (targetPlayer == mp_player->game()->previousPlayer(mp_player))
        ){
            PlayingCard* hit = new CardBang(mp_player->game(), -1, CardBang::Heavy, SUIT_INVALID, 5);
            hit->setVirtual(targetCard);
            hit->play(targetPlayer);
        }
    }
}

bool CharacterHeavy::hasBangSymbol(PlayingCard* card){
    switch(card->type()) {
        case CARD_BANG:
        case CARD_DOUBLE_BANG:
        case CARD_DIRECT_HIT:
            return true;
        default:
            return false;
            
    }
    return false;
}
