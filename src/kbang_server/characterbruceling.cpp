#include "characterbruceling.h"
#include "playingcard.h"
#include "reactioncard.h"
#include "cardteamfortressbang.h"
#include "cardmissed.h"
#include "weaponcard.h"
#include <iostream>

CharacterBruceLing::CharacterBruceLing(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
            setCharacterType(CHARACTER_BRUCE_LING);
            m_items = itemNumber;
        
}

int CharacterBruceLing::items(){
    return m_items;
}

void CharacterBruceLing::resetAbility(){
    m_items = itemNumber;
}

void CharacterBruceLing::itemToken(){
    m_items = m_items - 1;
}
