#include "characterjoeljanis.h"
#include "playingcard.h"
#include "reactioncard.h"
#include "cardteamfortressbang.h"
#include "cardmissed.h"

CharacterJoelJanis::CharacterJoelJanis(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_JOEL_JANIS);
}

void CharacterJoelJanis::playCard(PlayingCard* card)
{
    if (card->color() != COLOR_BROWN){
        card->setAct(true);
    }
    card->play();
}

void CharacterJoelJanis::respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard){
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
                        case REACTION_CUSTOMS:
                        case REACTION_NONE:
                            CharacterBase::respondCard(reactionHandler, targetCard);
                        break;
                        case REACTION_BANG:
                        case REACTION_GATLING:
                        {
                            if ( (targetCard->color() != COLOR_BROWN)){
                                CardMissed* missed0 =  qobject_cast<CardMissed*>(targetCard);
                                if (missed0 != 0){
                                    PlayingCard* missed = new CardMissed(mp_player->game(), -1, CardMissed::Missed, SUIT_INVALID, 5);
                                    missed->setVirtual(targetCard);
                                    CharacterBase::respondCard(reactionHandler, missed);
                                }
                                else {
                                    CharacterBase::respondCard(reactionHandler, targetCard);
                                }
                            }
                            else {
                                CharacterBase::respondCard(reactionHandler, targetCard);
                            }
                         }
                         break;
                         case REACTION_DUEL:
                         case REACTION_INDIANS:
                          {
                            if ( (targetCard->color() != COLOR_BROWN)){
                                CardBang* bang0 =  qobject_cast<CardBang*>(targetCard);
                                if (bang0 != 0){
                                  PlayingCard* bang = new CardBang(mp_player->game(), -1, CardBang::Bang, SUIT_INVALID, 5);
                                  bang->setVirtual(targetCard);
                                  CharacterBase::respondCard(reactionHandler, bang);
                                }
                                else {
                                    CharacterBase::respondCard(reactionHandler, targetCard);
                                }  
                            }
                            else {
                                 CharacterBase::respondCard(reactionHandler, targetCard);
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

