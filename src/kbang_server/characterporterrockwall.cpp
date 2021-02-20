#include "characterporterrockwall.h"
#include "gametable.h"
#include "gamecycle.h"
#include "player.h"
#include "cardbang.h"
#include "gameexceptions.h"

CharacterPorterRockwall::CharacterPorterRockwall(QObject *parent):
        CharacterBase(parent, CHARACTER_PORTER_ROCKWALL)
{
    
}

void CharacterPorterRockwall::useAbility(QList<PlayingCard*> cards, Player* targetPlayer)
{
    if (cards.empty()) throw BadUsageException();
    if (cards.size() == 1) throw BadUsageException();
    PlayingCard* targetCard = cards.at(0);
    if (targetCard->owner() != mp_player) throw BadUsageException();
    if (targetCard->pocket() != POCKET_HAND) throw BadUsageException();
    PlayingCard* targetCard2 = cards.at(1);
    if (targetCard2->owner() != mp_player) throw BadUsageException();
    if (targetCard2->pocket() != POCKET_HAND) throw BadUsageException();
     mp_bang = new CardBang(mp_player->game(), -1, CardBang::Unlimited, SUIT_INVALID, 5);
     mp_bang->setVirtual(targetCard);
     mp_bang->play(targetPlayer);
     gameTable().cancelCard(targetCard2);
    notifyAbilityUse();
     
}

