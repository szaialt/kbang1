#include "characterlinusyale.h"
#include "playingcard.h"
#include "player.h"
#include "gametable.h"

CharacterLinusYale::CharacterLinusYale(QObject* parent):
        CharacterBase(parent, CHARACTER_LINUS_YALE)        
{
}

int CharacterLinusYale::maxLifePoints() const
{
  return 5;
}
