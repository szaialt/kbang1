#include "charactersoldier.h"
#include "playingcard.h"
#include "reactioncard.h"
#include "cardteamfortressbang.h"
#include "cardmissed.h"
#include "weaponcard.h"

CharacterSoldier::CharacterSoldier(QObject* parent, Type type):
    CharacterBase(parent, CHARACTER_UNKNOWN),
    m_type(type){
        switch(type) {
        case Soldier:
            setCharacterType(CHARACTER_SOLDIER);
            break;
        case LlaneroSolitario:
            setCharacterType(CHARACTER_LLANERO_SOLITARIO);
            break;
        case SergeantOReilly:
            setCharacterType(CHARACTER_SERGEANT_O_REILLY);
            break;
        }
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
                        case REACTION_TAKER_BANG:
                        case REACTION_NONE:
                            CharacterBase::respondCard(reactionHandler, targetCard);
                        break;
                        case REACTION_GATLING:
                         {
                             if (reactionCard->type() == CARD_BROWN_SHOW_TIME){
                                PlayingCard* weapon = new WeaponCard(mp_player->game(), -1, WeaponCard::Walker, SUIT_INVALID, 10);
                                weapon->setVirtual(mp_player, POCKET_HAND);
                                CharacterBase::respondCard(reactionHandler, weapon); 
                             }
                             else {
                                PlayingCard* missed = new CardMissed(mp_player->game(), -1, CardMissed::Missed, SUIT_INVALID, 5);
                                missed->setVirtual(mp_player, POCKET_HAND);
                                CharacterBase::respondCard(reactionHandler, missed);
                             }
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

