#include "characterbushidobill.h"
#include "playingcard.h"
#include "reactioncard.h"
#include "cardteamfortressbang.h"
#include "cardmissed.h"
#include "cardmultishoot.h"
#include "weaponcard.h"

CharacterBushidoBill::CharacterBushidoBill(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
        setCharacterType(CHARACTER_BUSHIDO_BILL);
}

void CharacterBushidoBill::respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard){
    if (reactionHandler == 0) return;
    ReactionCard* reactionCard = static_cast<ReactionCard*>(reactionHandler);
    if (reactionCard == 0){
        CharacterBase::respondPass(reactionHandler);
    }
    else {
            if (mp_player->handSize() < 1){
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
                             if (reactionCard->type() == CARD_BROWN_SHOW_TIME){
                                PlayingCard* weapon = new WeaponCard(mp_player->game(), -1, WeaponCard::Walker, targetCard->suit(), targetCard->rank());
                                weapon->setVirtual(mp_player, POCKET_HAND);
                                CharacterBase::respondCard(reactionHandler, weapon); 
                             }
                             else {
                                PlayingCard* missed = new CardMissed(mp_player->game(), -1, CardMissed::Missed, targetCard->suit(), targetCard->rank());
                                missed->setVirtual(mp_player, POCKET_HAND);
                                CharacterBase::respondCard(reactionHandler, missed);
                             }
                         }
                         break;
                         case REACTION_DUEL:
                         case REACTION_INDIANS:
                         case REACTION_INDIAN_BANG:
                         case REACTION_INDIAN_BANG_WITH_BARREL: 
                          {
                             PlayingCard* bang = new CardBang(mp_player->game(), -1, CardBang::Bang, targetCard->suit(), targetCard->rank());
                             bang->setVirtual(mp_player, POCKET_HAND);
                             CharacterBase::respondCard(reactionHandler, bang);
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

