#include "characterninaninelives.h"
#include "player.h"
#include "gamecycle.h"
#include "cardbang.h"
#include "gametable.h"

CharacterNinaNineLives::CharacterNinaNineLives(QObject* parent):
        CharacterBase(parent, CHARACTER_NINA_NINE_LIVES)
{
}

int CharacterNinaNineLives::maxLifePoints() const
{
  return 3;
}

bool CharacterNinaNineLives::check(PlayingCard* card)
{
    return  (card->suit() == SUIT_SPADES);
}
