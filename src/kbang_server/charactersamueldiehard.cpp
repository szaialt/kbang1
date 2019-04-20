#include "charactersamueldiehard.h"
#include "player.h"
#include "gamecycle.h"
#include "cardbang.h"
#include "gametable.h"

CharacterSamuelDiehard::CharacterSamuelDiehard(QObject* parent):
        CharacterBase(parent, CHARACTER_SAMUEL_DIEHARD)
{
}

void CharacterSamuelDiehard::draw(bool specialDraw)
{
    CharacterBase::draw(0);
    QList<PlayingCard*> myHand = mp_player->hand();
    PlayingCard* last = myHand.last();
    PlayingCard* oneButLast = myHand.at(myHand.size() - 2);
    if ((last->suit() == SUIT_HEARTS) || (oneButLast->suit() == SUIT_HEARTS)){
        mp_player->modifyLifePoints(1, 0);
    }
}

