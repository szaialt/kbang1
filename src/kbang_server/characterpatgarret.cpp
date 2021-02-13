#include "characterpatgarret.h"
#include "player.h"
#include "gamecycle.h"
#include "cardjail.h"
#include "gameeventmanager.h"
#include "gametable.h"

CharacterPatGarrett::CharacterPatGarrett(QObject* parent):
        CharacterBase(parent, CHARACTER_PAT_GARRETT)
       
{
        m_canUseAbility = true;
}

void CharacterPatGarrett::useAbility(QList<PlayingCard*> cards, Player* targetPlayer){
    if (cards.empty()){
        throw BadCardException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->isWeapon()){
            
            gameTable().playerDiscardCard(targetCard);
            
            CardJail* jail = new CardJail(mp_player->game(), 0, CardJail::Jail, targetCard->suit(), targetCard->rank(), 8);
            targetPlayer->appendCardToTable(jail);
            jail->setOwner(targetPlayer);
            jail->setPocket(POCKET_TABLE);
            jail->registerPlayer(targetPlayer);
            
            mp_player->game()->gameEventManager().onPlayerPlayCardOnTable(mp_player, jail, targetPlayer);
            mp_player->checkEmptyHand();
            mp_player->game()->gameEventManager().onPlayerUpdated(mp_player);

            notifyAbilityUse();
        }
        else throw BadUsageException();
        
    }
} 

void CharacterPatGarrett::resetAbility(){
    m_canUseAbility = true;
}
