#include "charactercaptbarret.h"


CharacterCaptBarret::CharacterCaptBarret(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_CAPT_BARRETT);
}

int CharacterCaptBarret::maxLifePoints() const
{
  return 2;
}
