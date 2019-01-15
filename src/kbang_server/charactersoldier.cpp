#include "charactersoldier.h"
#include "playingcard.h"
#include "reactioncard.h"
#include "cardteamfortressbang.h"
#include "cardmissed.h"

CharacterSoldier::CharacterSoldier(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_SOLDIER);
}

void CharacterSoldier::respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard){
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
                        case REACTION_BANG:
                        case REACTION_NONE:
                            CharacterBase::respondCard(reactionHandler, targetCard);
                        break;
                        case REACTION_GATLING:
                         {
                                PlayingCard* missed = new CardMissed(mp_player->game(), -1, CardMissed::Missed, SUIT_INVALID, 5);
                                missed->setVirtual(mp_player, POCKET_HAND);
                                CharacterBase::respondCard(reactionHandler, missed);
                         }
                         break;
                         case REACTION_INDIANS:
                          {
                             PlayingCard* bang = new CardBang(mp_player->game(), -1, CardBang::Bang, SUIT_INVALID, 5);
                             bang->setVirtual(mp_player, POCKET_HAND);
                             CharacterBase::respondCard(reactionHandler, bang);
                         }
                         break;
                    }
                    
                    notifyAbilityUse();
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

