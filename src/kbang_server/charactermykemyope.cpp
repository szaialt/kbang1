#include "charactermykemyope.h"
#include "playingcard.h"

CharacterMykeMyope::CharacterMykeMyope(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_MYKE_MYOPE);
}

int CharacterMykeMyope::maxLifePoints() const
{
  return 6;
}

void CharacterMykeMyope::playCard(PlayingCard* card){
    if (card->isWeapon()){
        gameTable().playerDrawFromDeck(mp_player, 2);
        gameTable().playerPlayCard(card);
     }
    else {
        card->play();
    }
}
