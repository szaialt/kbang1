#include "characterjaremybaile.h"


CharacterJaremyBaile::CharacterJaremyBaile(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_JAREMY_BAILE);
}

int CharacterJaremyBaile::maxLifePoints() const
{
  return 3;
}
