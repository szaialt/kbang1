#include "characterdemoman.h"
#include "playingcard.h"
#include "cardbang.h"

CharacterDemoman::CharacterDemoman(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_DEMOMAN);
}

void CharacterDemoman::playCard(PlayingCard* card, Player* targetPlayer){
    if (card == 0){
        throw BadCardException();
    }
    else {
        if (card->owner() != mp_player) throw BadCardException();
        if (card->pocket() != POCKET_HAND) throw BadCardException();
        if (card->type() == CARD_BANG) {
            PlayingCard* doubleBang = new CardBang(mp_player->game(), 0, CardBang::DoubleBang, SUIT_INVALID,    10);
            doubleBang->setVirtual(card);
            doubleBang->play(targetPlayer);
        }
        else {
            card->play(targetPlayer);
        }
    }
}


