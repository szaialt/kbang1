#include "characterbartbarber.h"
#include "cardbarrel.h"
#include "player.h"
#include "gamecycle.h"

CharacterBartBarber::CharacterBartBarber(QObject* parent):
        CharacterBase(parent, CHARACTER_BART_BARBER),
        mp_integratedCustoms(0)
{
}

void CharacterBartBarber::draw(bool specialDraw)
{
    if (mp_integratedCustoms == 0) {
        mp_integratedCustoms = new CardCustoms(mp_player->game(), 0, SUIT_INVALID, 2);
        mp_integratedCustoms->setVirtual(mp_player, POCKET_TABLE);
    }
    gameCycle().playCard(mp_player, mp_integratedCustoms);
    CharacterBase::draw(specialDraw);
}
