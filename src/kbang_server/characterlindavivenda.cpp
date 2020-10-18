#include "characterlindavivenda.h"


CharacterLindaVivenda::CharacterLindaVivenda(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_LINDA_VIVENDA);
}

int CharacterLindaVivenda::maxLifePoints() const
{
  return 5;
}
