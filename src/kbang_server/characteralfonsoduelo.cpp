#include "characteralfonsoduelo.h"
#include "player.h"
#include "gamecycle.h"
#include "cardduel.h"
#include "cardbang.h"

CharacterAlfonsoDuelo::CharacterAlfonsoDuelo(QObject* parent):
        CharacterBase(parent, CHARACTER_ALFONSO_DUELO)
       
{
}

void CharacterAlfonsoDuelo::useAbility(QList<PlayingCard*> cards, Player* targetPlayer){
    if (cards.empty()){
        throw BadCardException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->type() == CARD_BANG){
            CardDuel* duel = new CardDuel(mp_player->game(), 0, CardDuel::Duel, targetCard->suit(), targetCard->rank());
            duel->setVirtual(targetCard);
            duel->play(targetPlayer);
            notifyAbilityUse();
        }
        else throw BadUsageException();
        
    }
} 
