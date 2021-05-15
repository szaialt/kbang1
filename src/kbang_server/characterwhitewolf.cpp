#include "characterwhitewolf.h"
#include "player.h"
#include "gamecycle.h"
#include "cardbang.h"
#include "cardmissed.h"
#include "reactionhandler.h"

CharacterWhiteWolf::CharacterWhiteWolf(QObject* parent, Type type):
    CharacterBase(parent, CHARACTER_UNKNOWN),
    m_type(type)
       
{
    switch(type) {
        case WhiteWolf:
            setCharacterType(CHARACTER_WHITE_WOLF);
            break;
        case FlintDixon:
            setCharacterType(CHARACTER_FLINT_DIXON);
            break;
        }
}

void CharacterWhiteWolf::useAbility(QList<PlayingCard*> cards, Player* targetPlayer){
    if (cards.empty()){
        throw BadCardException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->owner() != mp_player) throw BadCardException();
        if (targetCard->pocket() != POCKET_HAND) throw BadCardException();
        if (targetCard->type() != CARD_BANG) throw BadCardException();
        if (characterType() == CHARACTER_WHITE_WOLF){
            PlayingCard* hit = new CardBang(mp_player->game(), -1, CardBang::IndianBang, targetCard->suit(), targetCard->rank());
            hit->setVirtual(targetCard);
            hit->play(targetPlayer);
        }
        if (characterType() == CHARACTER_FLINT_DIXON){
            PlayingCard* hit = new CardBang(mp_player->game(), -1, CardBang::FlintIndianBang, targetCard->suit(), targetCard->rank());
            hit->setVirtual(targetCard);
            hit->play(targetPlayer);
        }
        notifyAbilityUse();
    }
} 

