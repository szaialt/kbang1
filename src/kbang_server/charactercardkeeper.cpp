#include "charactercardkeeper.h"

CharacterCardKeeper::CharacterCardKeeper(QObject* parent, Type type):
        CharacterBase(parent, CHARACTER_UNKNOWN),
        m_type(type)
{
    switch(type) {
    case BillyLonglife:
        setCharacterType(CHARACTER_BILLY_LONGLIFE);
        break;
    }
}

int CharacterCardKeeper::cardKeeping() const
{
    //if (characterType() == CHARACTER_BILLY_LONGLIFE)
    return 5;
}
