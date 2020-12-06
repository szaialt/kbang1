#include "characteroneeyedjack.h"


CharacterOneEyedJack::CharacterOneEyedJack(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_ONE_EYED_JACK);
}

int CharacterOneEyedJack::maxLifePoints() const
{
  return 5;
}
