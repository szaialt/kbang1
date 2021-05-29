#include "characterjuanmiranda.h"
#include "playingcard.h"
#include "reactioncard.h"
#include "cardbang.h"
#include "gamecycle.h"

CharacterJuanMiranda::CharacterJuanMiranda(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_JUAN_MIRANDA);
}

void CharacterJuanMiranda::respondPass(ReactionHandler* reactionHandler){
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
                            CharacterBase::respondPass(reactionHandler);
                        break;
                        case REACTION_BANG:
                        case REACTION_GATLING:
                        case REACTION_INDIANS:
                        case REACTION_DUEL:
                        case REACTION_INDIAN_BANG:
                        case REACTION_INDIAN_BANG_WITH_BARREL: 
                        {
                            PlayingCard* checkedCard = gameTable().checkDeck();
                            bool checkResult = check(checkedCard);
                            if (checkResult){
                                 PlayingCard* backfire = new CardBang(mp_player->game(), -1, CardBang::Backfire, SUIT_INVALID, 5);
                                 backfire->setVirtual(mp_player, POCKET_HAND);
                                 mp_player->game()->gameCycle().playCard(mp_player, backfire, reactionHandler->causedBy());
                             }
                             CharacterBase::respondPass(reactionHandler);
                             
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
            CharacterBase::respondPass(reactionHandler);
        }
    }
}

bool CharacterJuanMiranda::check(PlayingCard* card)
{
    if (card->suit() == SUIT_SPADES) return false;
    if (card->suit() == SUIT_CLUBS) return false;
    return true;
}

