#include "characterninaninelives.h"
#include "player.h"
#include "gamecycle.h"
#include "cardbang.h"
#include "gametable.h"

CharacterNinaNineLives::CharacterNinaNineLives(QObject* parent):
        CharacterBase(parent, CHARACTER_NINA_NINE_LIVES)
{
    m_times = 0;
}

int CharacterNinaNineLives::maxLifePoints() const
{
  return 3;
}

bool CharacterNinaNineLives::check(PlayingCard* card)
{
    m_times++;
    return  (card->suit() == SUIT_CLUBS);
}

bool CharacterNinaNineLives::canUseAbility(){
    return m_times < 9;
}
