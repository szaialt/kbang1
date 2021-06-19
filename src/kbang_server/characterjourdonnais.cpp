#include "characterjourdonnais.h"
#include "player.h"
#include "gamecycle.h"
#include "cardbang.h"
#include "cardmissed.h"
#include "gametable.h"
#include <algorithm>

CharacterJourdonnais::CharacterJourdonnais(QObject* parent):
        CharacterBase(parent, CHARACTER_JOURDONNAIS)
{
  canCheck = true;
}

void CharacterJourdonnais::respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard){
    if (reactionHandler == 0) return;
    ReactionCard* reactionCard = static_cast<ReactionCard*>(reactionHandler);
    if (reactionCard == 0){
        CharacterBase::respondPass(reactionHandler);
    }
    else {
            if (mp_player->game()->gameCycle().currentPlayer() != mp_player){
                try {
                    if  (canCheck){
                      switch(reactionHandler->reactionType()) {
                        case REACTION_GENERALSTORE:
                        case REACTION_HEALING_BANG:
                        case REACTION_LASTSAVE:
                        case REACTION_LUCKYDUKE:
                        case REACTION_KITCARLSON:
                        case REACTION_TAKER_BANG:
                        case REACTION_DUEL:
                        case REACTION_INDIANS:
                        case REACTION_CUSTOMS:
                        case REACTION_INDIAN_BANG:
                        case REACTION_NONE:
                            CharacterBase::respondCard(reactionHandler, targetCard);
                        break;
                        case REACTION_GATLING:
                        case REACTION_BANG:
                          {
                              
                                PlayingCard* checkedCard = mp_player->game()->gameTable().checkDeck();
                                bool checkResult = check(checkedCard);
                                if (checkResult){
                                    PlayingCard* missed = new CardMissed(mp_player->game(), -1, CardMissed::Missed, targetCard->suit(), targetCard->rank());
                                    missed->setVirtual(mp_player, POCKET_HAND);
                                    CharacterBase::respondCard(reactionHandler, missed);
                                    canCheck = false;
                                }
                                else {
                                    CharacterBase::respondCard(reactionHandler, targetCard);
                                    canCheck = false;
                               }
                          }
                        break;
                            case REACTION_INDIAN_BANG_WITH_BARREL: {
                                  PlayingCard* checkedCard = mp_player->game()->gameTable().checkDeck();
                                 bool checkResult = check(checkedCard);
                                 if (checkResult){
                                    PlayingCard* bang = new CardBang(mp_player->game(), -1, CardBang::Bang, targetCard->suit(), targetCard->rank());
                                    bang->setVirtual(mp_player, POCKET_HAND);
                                    CharacterBase::respondCard(reactionHandler,  bang);
                                    canCheck = false;
                               }
                                else {
                                   CharacterBase::respondCard(reactionHandler,   targetCard);
                                   canCheck = false;
                                  }
                               
                               }
                               break;
                        }
                         
                      
                    notifyAbilityUse();
                    } 
                    else {
                        CharacterBase::respondCard(reactionHandler, targetCard);
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

void CharacterJourdonnais::resetAbility(){
    canCheck = true;
}

void CharacterJourdonnais::inactivate(){
    canCheck = false;
}

bool CharacterJourdonnais::check(PlayingCard* card)
{
    if (card->suit() == SUIT_HEARTS) return true;
    return false;
}
