#include "charactergvblack.h"
#include "playingcard.h"
#include "cardbang.h"
#include "cardtakerbang.h"

CharacterGVBlack::CharacterGVBlack(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_G_V_BLACK);
}

void CharacterGVBlack::useAbility(QList<PlayingCard*> cards){
    if (cards.size() < 2){
        throw BadCardException();
    }
    PlayingCard* card = cards.at(0);
    if (card == 0){
        throw BadCardException();
    }
    PlayingCard* card2 = cards.at(1);
    if (card2 == 0){
        throw BadCardException();
    }
    else {
        if (card->owner() != mp_player) throw BadCardException();
        if (card->pocket() != POCKET_HAND) throw BadCardException();
        if (card->type() == CARD_BANG) {
            PlayingCard* taker = new CardTakerBang(mp_player->game(), 0, SUIT_INVALID,    10);
            taker->setVirtual(card);
            taker->play(card2);
        }
        else {
            throw BadUsageException();
        }
    }
}


