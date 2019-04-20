#include "characterdanquake.h"
#include "player.h"
#include "gamecycle.h"
#include "cardbang.h"
#include "gametable.h"

CharacterDanQuake::CharacterDanQuake(QObject* parent):
        CharacterBase(parent, CHARACTER_DAN_QUAKE)
{
}

void CharacterDanQuake::draw(bool specialDraw)
{
    if (mp_player->lifePoints() > mp_player->maxLifePoints()){
        PlayingCard* checkedCard = gameTable().checkDeck();
        bool checkResult = check(checkedCard);
        if (checkResult){
            mp_player->modifyLifePoints(-1, 0);
            notifyAbilityUse();
            
        }
    }
    CharacterBase::draw(0);
}

bool CharacterDanQuake::check(PlayingCard* card)
{
    return  (card->suit() == SUIT_SPADES);
}
