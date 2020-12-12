#include "charactertobiasthemole.h"


CharacterTobiasTheMole::CharacterTobiasTheMole(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_TOBIAS_THE_MOLE);
}

int CharacterTobiasTheMole::maxLifePoints() const
{
  return 5;
}
