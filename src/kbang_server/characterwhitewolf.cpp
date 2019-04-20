#include "characterwhitewolf.h"
#include "player.h"
#include "gamecycle.h"
#include "cardbang.h"
#include "cardmissed.h"
#include "reactionhandler.h"

CharacterWhiteWolf::CharacterWhiteWolf(QObject* parent):
        CharacterBase(parent, CHARACTER_WHITE_WOLF)
       
{
}

void CharacterWhiteWolf::useAbility(QList<PlayingCard*> cards, Player* targetPlayer){
    if (cards.empty()){
        throw BadCardException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->owner() != mp_player) throw BadCardException();
        if (targetCard->pocket() != POCKET_HAND) throw BadCardException();
        if (targetCard->color() != COLOR_BLUE) throw BadCardException();
        PlayingCard* hit = new CardBang(mp_player->game(), -1, CardBang::IndianBang, SUIT_INVALID, 5);
        hit->setVirtual(targetCard);
        hit->play(targetPlayer);
        notifyAbilityUse();
    }
} 

