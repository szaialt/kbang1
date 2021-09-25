#include "characterdynamitedick.h"
#include "game.h"
#include "playingcard.h"

CharacterDynamiteDick::CharacterDynamiteDick(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_DYNAMITE_DICK);
}

int CharacterDynamiteDick::maxLifePoints() const
{
  return 5;
}

void CharacterDynamiteDick::useAbility() 
{
    try {
        mp_player->game()->gameTable().playerDrawDynamiteFromGraveyard(mp_player);
    }
    catch (BadGameStateException ex){
        throw BadUsageException();
    }

}

