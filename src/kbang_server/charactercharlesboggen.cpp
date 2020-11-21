#include "charactercharlesboggen.h"
#include "playingcard.h"
#include "reactioncard.h"
#include "cardteamfortressbang.h"
#include "cardmissed.h"

CharacterCharlesBoggen::CharacterCharlesBoggen(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
        setCharacterType(CHARACTER_CHARLES_BOGGEN);
}

void CharacterCharlesBoggen::respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard){
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
                        case REACTION_NONE:
                        case REACTION_GATLING:
                        case REACTION_INDIANS:
                        case REACTION_CUSTOMS:
                            CharacterBase::respondCard(reactionHandler, targetCard);
                        break;
                        case REACTION_BANG:
                         {
                             ReactionCard* reactionCard = static_cast<ReactionCard*>(reactionHandler);
                             if (reactionCard->type() == CARD_BANG){
                                 CharacterBase::respondCard(reactionHandler, targetCard);
                                 return;
                             }
                             else if (reactionCard->type() == CARD_INDIAN_BANG){
                                 PlayingCard* bang = new CardBang(mp_player->game(), -1, CardBang::Bang, SUIT_INVALID, 5);
                                 bang->setVirtual(mp_player, POCKET_HAND);
                                 CharacterBase::respondCard(reactionHandler, bang);
                                 notifyAbilityUse();
                                 return;
                            }
                            PlayingCard* missed = new CardMissed(mp_player->game(), -1, CardMissed::Missed, SUIT_INVALID, 5);
                            missed->setVirtual(mp_player, POCKET_HAND);
                            CharacterBase::respondCard(reactionHandler, missed);
                            notifyAbilityUse();

                         }
                         break;
                    }
                    
                    
               }
                catch (BadUsageException ex){
                    qDebug() << "Ms Abigail using her ability. 3";
                    ex.debug();
                }
                catch (BadPlayerException ex){
                    qDebug() << "Ms Abigail using her ability. 4";
                    ex.debug();
                }
                
            }
            
        
        else {
            CharacterBase::respondCard(reactionHandler, targetCard);
        }
    }
}

