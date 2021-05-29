#include "characterantonycarma.h"
#include "playingcard.h"
#include "reactioncard.h"
#include "cardteamfortressbang.h"
#include "cardmissed.h"

CharacterAntonyCarma::CharacterAntonyCarma(QObject* parent):
    CharacterBase(parent, CHARACTER_ANTONY_CARMA){
} 

void CharacterAntonyCarma::respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard){
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
                    case REACTION_CUSTOMS:
                    case REACTION_NONE:
                        CharacterBase::respondCard(reactionHandler, targetCard);
                    break;
                    case REACTION_INDIAN_BANG:
                    case REACTION_INDIAN_BANG_WITH_BARREL: 
                         {
                                PlayingCard* bang = new CardBang(mp_player->game(), -1, CardBang::Bang, targetCard->suit(), targetCard->rank());
                                bang->setVirtual(mp_player, POCKET_HAND);
                                CharacterBase::respondCard(reactionHandler, bang);
                            }
                    case REACTION_BANG: 
                        {
                        if (reactionCard->type() == CARD_BANG){
                            CharacterBase::respondCard(reactionHandler, targetCard);
                            return;
                        }
                        PlayingCard* checkedCard = gameTable().checkDeck();
                        bool checkResult = check(checkedCard);
                        if (!checkResult){
                            CharacterBase::respondCard(reactionHandler, targetCard);
                            return;
                        }
                        else {
                            PlayingCard* missed = new CardMissed(mp_player->game(), -1, CardMissed::Missed, targetCard->suit(), targetCard->rank());
                            missed->setVirtual(mp_player, POCKET_HAND);
                            CharacterBase::respondCard(reactionHandler, missed);
                            notifyAbilityUse();
                        }
                    }
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

bool CharacterAntonyCarma::check(PlayingCard* card)
{
    return  (card->suit() == SUIT_CLUBS);
}

