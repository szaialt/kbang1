#include "characterphilthinwire.h"


CharacterPhilThinwire::CharacterPhilThinwire(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_PHIL_THINWIRE);
  m_defense = 0;
}

int CharacterPhilThinwire::maxLifePoints() const
{
  return 3;
}

void CharacterPhilThinwire::setDefense(){
    m_defense++;
}

void CharacterPhilThinwire::unsetDefense(){
    m_defense = 0;
}

bool CharacterPhilThinwire::isDefended(){
    return m_defense > 0;
}
