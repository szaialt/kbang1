#include "characterannerogers.h"
#include "playingcard.h"
#include "player.h"
#include "gametable.h"

CharacterAnneRogers::CharacterAnneRogers(QObject* parent):
        CharacterBase(parent, CHARACTER_ANNE_ROGERS),
        mp_integratedCard(0),
        mp_ownerOfCard(0)
{
}

void CharacterAnneRogers::useAbility(QList<PlayingCard*> cards){
    if (cards.empty()) throw new BadUsageException();
    if (cards.at(0) == 0) throw new BadUsageException();
    PlayingCard* targetCard = cards.at(0);
    if (targetCard->color() != COLOR_BLUE) throw new BadUsageException();
    mp_ownerOfCard = targetCard->owner();
    mp_integratedCard = targetCard;
    mp_player->game()->gameTable().playerStealCard(mp_player, targetCard);
    //gameCycle().playCard(mp_player, mp_integratedCard);
}

void CharacterAnneRogers::resetAbility(){
    mp_integratedCard->setOwner(mp_ownerOfCard);
    gameCycle().playCard(mp_player, mp_integratedCard);
    mp_ownerOfCard = 0;
    mp_integratedCard = 0;
}
