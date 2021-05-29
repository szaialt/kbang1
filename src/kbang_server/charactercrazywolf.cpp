#include "charactercrazywolf.h"
#include "playingcard.h"
#include "reactioncard.h"
#include "cardteamfortressbang.h"
#include "cardmissed.h"
#include "weaponcard.h"

CharacterCrazyWolf::CharacterCrazyWolf(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
            setCharacterType(CHARACTER_CRAZY_WOLF);
        
}

void CharacterCrazyWolf::respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard){
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
                        case REACTION_CUSTOMS:
                        case REACTION_NONE:
                            CharacterBase::respondCard(reactionHandler, targetCard);
                        break;
                        case REACTION_BANG:
                        case REACTION_TAKER_BANG:
                        case REACTION_GATLING:
                        case REACTION_INDIAN_BANG:
                        case REACTION_INDIAN_BANG_WITH_BARREL: 
                         {
                             if (reactionCard->type() == CARD_BROWN_SHOW_TIME){
                                CharacterBase::respondCard(reactionHandler, targetCard);
                             }
                             else {
                                 int defensiveValue = reactionCard->rank() + targetCard->rank();
                                 if (defensiveValue >= 20){
                                     PlayingCard* missed = new CardBang(mp_player->game(), -1, CardBang::Backfire, targetCard->suit(), targetCard->rank());
                                     missed->setVirtual(targetCard);
                                     CharacterBase::respondCard(reactionHandler, missed);
                                }
                                 else if (defensiveValue >= 17){
                                     PlayingCard* missed = new CardMissed(mp_player->game(), -1, CardMissed::Dodge, targetCard->suit(), targetCard->rank());
                                     missed->setVirtual(targetCard);
                                     CharacterBase::respondCard(reactionHandler, missed);
                                }
                                 else if (defensiveValue >= 13){
                                     PlayingCard* missed = new CardMissed(mp_player->game(), -1, CardMissed::Missed, targetCard->suit(), targetCard->rank());
                                     missed->setVirtual(targetCard);
                                     CharacterBase::respondCard(reactionHandler, missed);
                                }
                                 else {
                                     CharacterBase::respondCard(reactionHandler, targetCard);
                                }
                             }
                         }
                         break;
                        default:
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

