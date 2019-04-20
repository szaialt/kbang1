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
                    case REACTION_NONE:
                        CharacterBase::respondCard(reactionHandler, targetCard);
                    break;
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
                            if (reactionCard->type() == CARD_INDIAN_BANG){
                                PlayingCard* bang = new CardBang(mp_player->game(), -1, CardBang::Bang, SUIT_INVALID, 5);
                                bang->setVirtual(mp_player, POCKET_HAND);
                                CharacterBase::respondCard(reactionHandler, bang);
                            }
                            else {
                                PlayingCard* missed = new CardMissed(mp_player->game(), -1, CardMissed::Missed, SUIT_INVALID, 5);
                                missed->setVirtual(mp_player, POCKET_HAND);
                                CharacterBase::respondCard(reactionHandler, missed);
                            }
                            notifyAbilityUse();
                        }
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

bool CharacterAntonyCarma::check(PlayingCard* card)
{
    return  (card->suit() == SUIT_CLUBS);
}

