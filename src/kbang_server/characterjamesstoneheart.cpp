#include "characterjamesstoneheart.h"
#include "playingcard.h"
#include "player.h"
#include "gametable.h"

CharacterJamesStoneheart::CharacterJamesStoneheart(QObject* parent):
        CharacterBase(parent, CHARACTER_JAMES_STONEHEART)        
{
}

int CharacterJamesStoneheart::maxLifePoints() const
{
  return 5;
}
