#include "characterdaltongang.h"

CharacterDaltonGang::CharacterDaltonGang(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_DALTON_GANG);
}

int CharacterDaltonGang::maxLifePoints() const
{
  return 3;
}
