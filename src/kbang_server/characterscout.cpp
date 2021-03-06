#include "characterscout.h"
#include "playingcard.h"
#include "reactioncard.h"
#include "cardteamfortressbang.h"
#include "cardmissed.h"
#include "weaponcard.h"

CharacterScout::CharacterScout(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_SCOUT);
}

int CharacterScout::maxLifePoints() const
{
  return 3;
}

void CharacterScout::respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard){
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
                        case REACTION_TAKER_BANG:
                        case REACTION_CUSTOMS:
                        case REACTION_NONE:
                            CharacterBase::respondCard(reactionHandler, targetCard);
                        break;
                        case REACTION_BANG:
                        case REACTION_GATLING:
                        {
                            if ((reactionCard->color() == COLOR_BROWN) && (targetCard->color() == COLOR_BROWN)){
                                if (reactionCard->type() ==     CARD_BROWN_SHOW_TIME){
                                    PlayingCard* weapon = new WeaponCard(mp_player->game(), -1, WeaponCard::Walker, targetCard->suit(), targetCard->rank());
                                    weapon->setVirtual(mp_player, POCKET_HAND);
                                    CharacterBase::respondCard(reactionHandler, weapon); 
                               }
                               else {
                                    PlayingCard* missed = new CardMissed(mp_player->game(), -1, CardMissed::Missed, targetCard->suit(), targetCard->rank());
                                    missed->setVirtual(targetCard);
                                    CharacterBase::respondCard(reactionHandler, missed);
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
                            if ((reactionCard->color() == COLOR_BROWN) && (targetCard->color() == COLOR_BROWN)){
                                  PlayingCard* bang = new CardBang(mp_player->game(), -1, CardBang::Bang, targetCard->suit(), targetCard->rank());
                                  bang->setVirtual(targetCard);
                                  CharacterBase::respondCard(reactionHandler, bang);
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

