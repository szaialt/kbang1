#include "characterjosebasset.h"
#include "playingcard.h"

CharacterJoseBasset::CharacterJoseBasset(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_JOSEY_BASSET);
  m_canUseAbility = true;
}

void CharacterJoseBasset::draw(bool specialDraw){
    if ((!specialDraw)){
        m_canUseAbility = false;
        CharacterBase::draw(false);
    }
}

void CharacterJoseBasset::useAbility(){
    if (!m_canUseAbility) throw BadUsageException();
    mp_player->game()->gameTable().playerDrawFromDeck(mp_player, 4, 0);
    m_canUseAbility = false;
    mp_player->game()->gameCycle().joseBassetFinishesHerTurnByAbility(mp_player);
}

void CharacterJoseBasset::resetAbility(){
    m_canUseAbility = true;
}
