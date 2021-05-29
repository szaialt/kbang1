#include "playingcard.h"
#include "reactioncard.h"
#include "cardteamfortressbang.h"
#include "cardbang.h"
#include "charactertedrevenge.h"

CharacterTedRevenge::CharacterTedRevenge(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
            setCharacterType(CHARACTER_TED_REVENGE);
        
}

void CharacterTedRevenge::respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard){
    if (reactionHandler == 0) return;
    ReactionCard* reactionCard = static_cast<ReactionCard*>(reactionHandler);
    if (reactionCard == 0){
        CharacterBase::respondPass(reactionHandler);
    }
    else {
            if (mp_player->game()->gameCycle().currentPlayer() != mp_player){
                try {
                    switch(reactionHandler->reactionType()) {
                        case REACTION_GENERALSTORE:
                        case REACTION_HEALING_BANG:
                        case REACTION_LASTSAVE:
                        case REACTION_LUCKYDUKE:
                        case REACTION_KITCARLSON:
                        case REACTION_DUEL:
                        case REACTION_GATLING:
                        case REACTION_INDIANS:   
                        case REACTION_TAKER_BANG:
                        case REACTION_CUSTOMS:
                        case REACTION_INDIAN_BANG:
                        case REACTION_INDIAN_BANG_WITH_BARREL: 
                        case REACTION_NONE:
                            CharacterBase::respondCard(reactionHandler, targetCard);
                        break;
                        case REACTION_BANG:{
                            CharacterBase::respondCard(reactionHandler, targetCard);
                            if (m_times < 1){
                                PlayingCard* revenge = new CardBang(mp_player->game(), -1, CardBang::Revenge, targetCard->suit(), targetCard->rank());
                                     revenge->setVirtual(mp_player, POCKET_HAND);
                                     CharacterBase::respondCard(reactionHandler, revenge);
                                m_times++;
                            }
                            
                        }
                        break;
                        
                    }
                    
                    notifyAbilityUse();
               }
                catch (BadUsageException ex){
                    ex.debug();
                }
                catch (BadPlayerException ex){
                    ex.debug();
                }
                
            }
            
        
        else {
            CharacterBase::respondCard(reactionHandler, targetCard);
        }
    }
}

void CharacterTedRevenge::resetAbility(){
    m_times = 0;
}
