#include "charactercardkeeper.h"

CharacterCardKeeper::CharacterCardKeeper(QObject* parent, Type type):
        CharacterBase(parent, CHARACTER_UNKNOWN),
        m_type(type)
{
    switch(type) {
    case BillyLonglife:
        setCharacterType(CHARACTER_BILLY_LONGLIFE);
        break;
    case MaxPainless:
        setCharacterType(CHARACTER_MAX_PAINLESS);
        break;
    }
}

int CharacterCardKeeper::maxLifePoints() const
{
    if (characterType() == CHARACTER_BILLY_LONGLIFE)
      return 4;
    if (characterType() == CHARACTER_MAX_PAINLESS)
      return 5;
}


int CharacterCardKeeper::cardKeeping() const
{
    if (characterType() == CHARACTER_BILLY_LONGLIFE)
      return 5;
    if (characterType() == CHARACTER_MAX_PAINLESS)
      return 4;
}
