#include "characterstonewalljackson.h"
#include "player.h"
#include "gamecycle.h"
#include "cardbang.h"
#include "cardmissed.h"
#include "gametable.h"
#include <algorithm>

CharacterStonewallJackson::CharacterStonewallJackson(QObject* parent):
        CharacterBase(parent, CHARACTER_STONEWALL_JACKSON)
{

}

void CharacterStonewallJackson::playCard(PlayingCard* card, Player* targetPlayer){
    if (card->type() == CARD_BANG){
        PlayingCard* checkedCard = mp_player->game()->gameTable().checkDeck();
        bool checkResult = check(checkedCard);
         if (!checkResult){
             CardBang* noHurting = new CardBang(mp_player->game(), 0, CardBang::NoHurtingBang, card->suit(), card->rank());
             noHurting->setVirtual(card);
             noHurting->play(targetPlayer);
         }
         else {
             CharacterBase::playCard(card, targetPlayer);
         }
    notifyAbilityUse();
    }
    else {
         CharacterBase::playCard(card, targetPlayer);
    }
}

void CharacterStonewallJackson::respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard){
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
                        case REACTION_GATLING:
                        case REACTION_DUEL:
                        case REACTION_INDIANS:
                        case REACTION_CUSTOMS:
                        case REACTION_NONE:
                            CharacterBase::respondCard(reactionHandler, targetCard);
                        break;
                        case REACTION_BANG:
                        {
                            if (reactionCard->type() == CARD_BANG){
                                PlayingCard* checkedCard = mp_player->game()->gameTable().checkDeck();
                                bool checkResult = check(checkedCard);
                                if (checkResult){
                                    PlayingCard* missed = new CardMissed(mp_player->game(), -1, CardMissed::Missed, SUIT_INVALID, 5);
                                    missed->setVirtual(mp_player, POCKET_HAND);
                                    CharacterBase::respondCard(reactionHandler, missed);
                                }
                            else {
                                CharacterBase::respondCard(reactionHandler, targetCard);
                            }
                         }
                         break;
                    }
                    
                    notifyAbilityUse();
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

bool CharacterStonewallJackson::check(PlayingCard* card)
{
    if (card->suit() == SUIT_DIAMONDS) return true;
    if (card->suit() == SUIT_HEARTS) return true;
    return false;
}
