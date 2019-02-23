#include "charactercrazybear.h"
#include "playingcard.h"
#include "cardbang.h"

CharacterCrazyBear::CharacterCrazyBear(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_CRAZY_BEAR);
  m_injury = 0;
}

void CharacterCrazyBear::playCard(PlayingCard* card, Player* targetPlayer){
    if (card == 0){
        throw BadCardException();
    }
    else {
        if (card->owner() != mp_player) throw BadCardException();
        if (card->pocket() != POCKET_HAND) throw BadCardException();
        if (card->type() == CARD_BANG) {
            m_injury = mp_player->maxLifePoints() - mp_player->lifePoints();
        }
        card->play(targetPlayer);
        
    }
}

int CharacterCrazyBear::injury(){
    return m_injury;
}
