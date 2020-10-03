#include "characterfelipedelgado.h"
#include "playingcard.h"

CharacterFelipeDelgado::CharacterFelipeDelgado(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_FELIPE_DELGADO);
  m_usedAbility = 0;
}

void CharacterFelipeDelgado::useAbility(QList<PlayingCard*> cards){
    if (m_usedAbility >= 2) throw BadUsageException();
    if (cards.empty()){
        throw BadCardException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->owner() != mp_player) throw BadCardException();
        if (targetCard->pocket() != POCKET_HAND) throw BadCardException();
        if (targetCard->color() != COLOR_GREEN) throw BadCardException();
        gameTable().cancelCard(targetCard);
        mp_player->game()->gameTable().playerDrawFromDeck(mp_player, 2, 0);
        m_usedAbility++;
    }
}

void CharacterFelipeDelgado::resetAbility(){
    m_usedAbility = 0;
}
