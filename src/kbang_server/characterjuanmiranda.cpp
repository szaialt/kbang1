#include "characterjuanmiranda.h"


CharacterJuanMiranda::CharacterJuanMiranda(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_JUAN_MIRANDA);
}

int CharacterJuanMiranda::maxLifePoints() const
{
  return 3;
}
