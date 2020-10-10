#include "charactergreenkatejanet.h"
#include "player.h"
#include "gamecycle.h"
#include "cardbang.h"
#include "cardbeer.h"

CharacterGreenKateJanet::CharacterGreenKateJanet(QObject* parent):
        CharacterBase(parent, CHARACTER_GREEN_KATE_JANET)
       
{
}

void CharacterGreenKateJanet::useAbility(QList<PlayingCard*> cards, Player* targetPlayer){
    if (cards.empty()){
        throw BadCardException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->color() != COLOR_GREEN){
            throw BadCardException();
        }
        if (targetCard->pocket() != POCKET_TABLE){
            throw BadCardException();
        }
        if (targetPlayer == player()){
            CardBeer* saloon = new CardBeer(player()->game(), 0, CardBeer::Saloon, targetCard->suit(), targetCard->rank());
            saloon->setVirtual(targetCard);
            saloon->play();
        }
        else {
            CardBang* bang = new CardBang(player()->game(), 0, CardBang::Bang, targetCard->suit(), targetCard->rank());
            bang->setVirtual(targetCard);
            bang->play(targetPlayer);
        }
        notifyAbilityUse();        
    }
} 
