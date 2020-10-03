#include "characterfastfranz.h"
#include "player.h"
#include "gamecycle.h"
#include "cardbang.h"
#include "gametable.h"

CharacterFastFranz::CharacterFastFranz(QObject* parent):
        CharacterBase(parent, CHARACTER_FAST_FRANZ)
{
}

int CharacterFastFranz::maxLifePoints() const
{
  return 2;
}

bool CharacterFastFranz::check(PlayingCard* card)
{
    return  (card->suit() != SUIT_SPADES);
}
