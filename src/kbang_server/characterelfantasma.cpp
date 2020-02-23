#include "characterelfantasma.h"
#include "player.h"
#include "gamecycle.h"

CharacterElFantasma::CharacterElFantasma(QObject* parent):
        CharacterBase(parent, CHARACTER_EL_FANTASMA)
{
}

void CharacterElFantasma::playerDied()
{
    if (mp_integratedBeer == 0){
        //CharacterBase::playerDied();
        mp_player->setAlive(true);
        mp_integratedBeer = new CardBeer(mp_player->game(), -1, CardBeer::Beer, SUIT_INVALID, 5);
        mp_integratedBeer->setVirtual(mp_player, POCKET_HAND);
    }
    CharacterBase::playCard(mp_integratedBeer);
    mp_integratedBeer = 0;
}

