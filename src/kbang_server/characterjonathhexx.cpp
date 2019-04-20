#include "characterjonathhexx.h"
#include "player.h"
#include "gamecycle.h"
#include "gametable.h"

CharacterJonathHexx::CharacterJonathHexx(QObject* parent):
        CharacterBase(parent, CHARACTER_JONATH_HEXX)
       
{
}

void CharacterJonathHexx::useAbility(QList<PlayingCard*> cards, Player* targetPlayer){
    if (cards.empty()){
        throw BadCardException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->color() == COLOR_BLUE){
            if (targetPlayer->isAlive()) throw BadUsageException();
            targetPlayer->setHexxZombie(true);
            gameTable().playerDiscardCard(targetCard);
            notifyAbilityUse();
        }
        else throw BadUsageException();
        
    }
} 
