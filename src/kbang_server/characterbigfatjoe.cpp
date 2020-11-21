#include "characterbigfatjoe.h"
#include "playingcard.h"

CharacterBigFatJoe::CharacterBigFatJoe(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_BIG_FAT_JOE);
  m_halfLife = false;
}

int CharacterBigFatJoe::maxLifePoints() const
{
  return 7;
}

void CharacterBigFatJoe::playCard(PlayingCard* card){
    if (card->type() == CARD_BEER){
        if (m_halfLife){
            m_halfLife = false;
            card->play();
        }
        else {
            m_halfLife = true;
            gameTable().playerPlayCard(card);
        }
    }
    else {
        card->play();
    }
}
