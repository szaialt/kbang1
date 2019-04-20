#include "characterabilitythief.h"
#include "player.h"
#include "gamecycle.h"
#include "cardcharm.h"

CharacterAbilityThief::CharacterAbilityThief(QObject* parent, Type type):
    CharacterBase(parent, CHARACTER_UNKNOWN),
    m_type(type)
       
{
    if (type == JimScarecrow)
        setCharacterType(CHARACTER_JIM_SCARECROW);
    else if (type == LadyBourbon)
        setCharacterType(CHARACTER_LADY_BURBOUN);
}

void CharacterAbilityThief::useAbility(QList<PlayingCard*> cards, Player* targetPlayer){
    if (cards.empty()){
        throw BadCardException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (characterType() == CHARACTER_JIM_SCARECROW){
            if ((targetCard->type() != CARD_PANIC) && (targetCard->type() != CARD_CATBALOU)){
                throw BadUsageException();
            }
        }
        else if (characterType() == CHARACTER_LADY_BURBOUN){
            if (targetCard->type() != CARD_BEER) {
                throw BadUsageException();
            }
        }
        CardCharm* charm = new CardCharm(mp_player->game(), 0, targetCard->suit(), targetCard->rank());
        charm->setVirtual(targetCard);
        charm->play(targetPlayer);
        notifyAbilityUse();
    }
} 
