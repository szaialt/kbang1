#include "characterturdferguson.h"
#include "playingcard.h"
#include "reactioncard.h"
#include "cardteamfortressbang.h"
#include "cardmissed.h"
#include "weaponcard.h"
#include <iostream>

CharacterTurdFerguson::CharacterTurdFerguson(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
            setCharacterType(CHARACTER_TURD_FERGUSON);
            m_used = false;
        
}

void CharacterTurdFerguson::respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard){
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
                        case REACTION_INDIANS:
                        case REACTION_NONE:
                            CharacterBase::respondCard(reactionHandler, targetCard);
                        break;
                        case REACTION_BANG:
                        case REACTION_TAKER_BANG:
                        case REACTION_GATLING:
                         {
                             if (reactionCard->type() == CARD_BROWN_SHOW_TIME){
                                CharacterBase::respondCard(reactionHandler, targetCard);
                             }
                             else {
                               
                                 if (!m_used){
                                     PlayingCard* missed = new CardMissed(mp_player->game(), -1, CardMissed::Missed, SUIT_INVALID, 5);
                                     missed->setVirtual(mp_player, POCKET_HAND);
                                     CharacterBase::respondCard(reactionHandler, missed);
                                     m_used = true;
                                 }
                                 else {
                                     CharacterBase::respondCard(reactionHandler, targetCard);
                                }
                             }
                         }
                        notifyAbilityUse();                   
                    
                    break;
                    default:
                    break;
                    }
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

void CharacterTurdFerguson::resetAbility(){
    m_used = false;
}
