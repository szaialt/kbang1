#include "charactercowboy.h"


CharacterCowboy::CharacterCowboy(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_COWBOY);
}

int CharacterCowboy::maxLifePoints() const
{
  return 5;
}
