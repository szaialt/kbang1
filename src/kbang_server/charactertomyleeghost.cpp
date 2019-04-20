#include "charactertomyleeghost.h"
#include "gametable.h"
#include "player.h"
#include "cardbang.h"
#include "gamecycle.h"

CharacterTomyLeeGhost::CharacterTomyLeeGhost(QObject* parent):
        CharacterBase(parent, CHARACTER_TOMY_LEE_GHOST)
{
    m_rounds = 2,
    m_isAlive = true;
    m_isAtFirstDead = false;
}

void CharacterTomyLeeGhost::decrementRounds(){
    if (m_isAtFirstDead){
         m_rounds--;
    }
}

void CharacterTomyLeeGhost::setDead(){
    if (m_rounds <= 0){
        m_isAlive = false;
    }
}

bool CharacterTomyLeeGhost::isAlive(){
    return m_isAlive;
}

bool CharacterTomyLeeGhost::isAtFirstDead(){
    return m_isAtFirstDead;
}

void CharacterTomyLeeGhost::setAtFirstDead(){
    m_isAtFirstDead = true;
}
