#include "charactercheckingroyal.h"
#include "player.h"
#include "gamecycle.h"
#include "cardbang.h"
#include "gametable.h"
#include <algorithm>

CharacterCheckingRoyal::CharacterCheckingRoyal(QObject* parent):
        CharacterBase(parent, CHARACTER_UNKNOWN)
{
    setCharacterType(CHARACTER_JOB_MUSHGROVE);
}

void CharacterCheckingRoyal::setPlayer(Player* player)
{
    CharacterBase::setPlayer(player);
    connect(player, SIGNAL(onHit(int,Player*)),
            this,   SLOT(onHit(int,Player*)));
}

void CharacterCheckingRoyal::onHit(int lifePoints, Player* causedBy)
{
   PlayingCard* checkedCard = gameTable().checkDeck();
        bool checkResult = check(checkedCard);
        if (checkResult){
        if (causedBy == 0 || causedBy == mp_player) return;
        notifyAbilityUse();
        for (int i = 0; i < lifePoints; ++i) {
            PlayingCard* targetCard = causedBy->getRandomCardFromHand();
            if (targetCard == 0) return;
            gameTable().playerDiscardCard(targetCard);
        }
        return;
    }
}

bool CharacterCheckingRoyal::check(PlayingCard* card)
{
    if (card->rank() > 10) return true;
    return false;
}
