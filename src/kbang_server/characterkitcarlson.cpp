#include "characterkitcarlson.h"
#include "gametable.h"
#include "gamecycle.h"
#include "playingcard.h"
#include "gameexceptions.h"
#include "gameeventmanager.h"

CharacterKitCarlson::CharacterKitCarlson(QObject *parent, Type type):
        CharacterBase(parent, CHARACTER_UNKNOWN),
        m_type(type)
{
        switch(type) {
        case KitCarlson:
            setCharacterType(CHARACTER_KIT_CARLSON);
            break;
        case RevJonathanRudd:
            setCharacterType(CHARACTER_REV_JONATHAN_RUDD);
            break;
        }
}


void CharacterKitCarlson::useAbility()
{
    gameCycle().draw(mp_player, 1);
}


void CharacterKitCarlson::draw(bool specialDraw)
{
    if (specialDraw) {
        notifyAbilityUse();
        gameTable().drawIntoSelection(3, mp_player);
        Q_ASSERT(gameTable().selection().size() == 3);
        if (characterType() == CHARACTER_REV_JONATHAN_RUDD){
           gameTable().drawHandIntoSelection(mp_player); 
        }
        gameCycle().setResponseMode(this, mp_player);
    } else {
        CharacterBase::draw(0);
    }
}

void CharacterKitCarlson::respondCard(PlayingCard* targetCard)
{
    if (targetCard->pocket() != POCKET_SELECTION)
        throw BadCardException();
    gameTable().playerPickFromSelection(mp_player, targetCard);
    if (gameTable().selection().size() == 1) {
        gameCycle().unsetResponseMode();
        gameTable().undrawFromSelection(gameTable().selection()[0]);
        Q_ASSERT(gameTable().selection().size() == 0);
    }
}

