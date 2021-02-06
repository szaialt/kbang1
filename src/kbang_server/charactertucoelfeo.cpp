#include "charactertucoelfeo.h"
#include "playingcard.h"
#include "reactioncard.h"
#include "cardteamfortressbang.h"
#include "cardmissed.h"
#include "weaponcard.h"
#include <iostream>

CharacterTucoElFeo::CharacterTucoElFeo(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
            setCharacterType(CHARACTER_TUCO_EL_FEO);
            m_items = itemNumber;
        
}

int CharacterTucoElFeo::items(){
    return m_items;
}

void CharacterTucoElFeo::resetAbility(){
    m_items = itemNumber;
}

void CharacterTucoElFeo::itemToken(){
    m_items = m_items - 1;
}
