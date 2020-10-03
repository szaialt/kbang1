#include "characterchosingthomas.h"
#include "playingcard.h"
#include "player.h"
#include "gametable.h"

CharacterChosingThomas::CharacterChosingThomas(QObject* parent):
        CharacterBase(parent, CHARACTER_CHOSING_THOMAS),
        m_canUseAbility(true)
{
}

bool CharacterChosingThomas::canUseAbility(){
    return m_canUseAbility;
}

void CharacterChosingThomas::resetAbility(){
    m_canUseAbility = true;
}

void CharacterChosingThomas::abilityUsed(){
    m_canUseAbility = false;
}
