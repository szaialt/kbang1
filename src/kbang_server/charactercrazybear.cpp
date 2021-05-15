#include "charactercrazybear.h"
#include "playingcard.h"
#include "cardbang.h"

CharacterCrazyBear::CharacterCrazyBear(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_CRAZY_BEAR);
}

int CharacterCrazyBear::injury(){
    return mp_player->maxLifePoints() - mp_player->lifePoints();
}
