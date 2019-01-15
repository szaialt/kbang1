#include "characterengineer.h"
#include "player.h"
#include "gamecycle.h"
#include "cardbang.h"
#include "cardmissed.h"
#include "reactionhandler.h"

CharacterEngineer::CharacterEngineer(QObject* parent):
        CharacterBase(parent, CHARACTER_ENGINEER)
       
{
}

void CharacterEngineer::useAbility(QList<PlayingCard*> cards, Player* targetPlayer){
    if (cards.empty()){
        throw BadCardException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->owner() != mp_player) throw BadCardException();
        if (targetCard->pocket() != POCKET_HAND) throw BadCardException();
        if (targetCard->color() != COLOR_BLUE) throw BadCardException();
        PlayingCard* hit = new CardBang(mp_player->game(), -1, CardBang::Bang, SUIT_INVALID, 5);
        hit->setVirtual(targetCard);
        hit->play(targetPlayer);
        notifyAbilityUse();
    }
} 

void CharacterEngineer::respondCard(ReactionHandler* reactionHandler, PlayingCard* targetCard){
    if (reactionHandler == 0) return;
    ReactionCard* reactionCard = static_cast<ReactionCard*>(reactionHandler);
    if (reactionCard == 0){
        CharacterBase::respondPass(reactionHandler);
    }
    switch(reactionHandler->reactionType()) {
        case REACTION_GENERALSTORE:
        case REACTION_HEALING_BANG:
        case REACTION_LASTSAVE:
        case REACTION_LUCKYDUKE:
        case REACTION_KITCARLSON:
        case REACTION_NONE:
            CharacterBase::respondCard(reactionHandler, targetCard);
            break;
        case REACTION_GATLING:
        case REACTION_BANG:
        {
            {
            if (targetCard->color() == COLOR_BLUE){
                PlayingCard* missed = new CardMissed(mp_player->game(), -1, CardMissed::Missed, SUIT_INVALID, 5);
                missed->setVirtual(targetCard);
                CharacterBase::respondCard(reactionHandler, missed);
            }
            else {
                CharacterBase::respondCard(reactionHandler, targetCard);
            }
            break;
        }
        case REACTION_INDIANS:
        case REACTION_DUEL: {
            if (targetCard->color() == COLOR_BLUE){
                PlayingCard* bang = new CardBang(mp_player->game(), -1, CardBang::Bang, SUIT_INVALID, 5);
                bang->setVirtual(targetCard);
                CharacterBase::respondCard(reactionHandler, bang);
            }
            else {
                CharacterBase::respondCard(reactionHandler, targetCard);
            }
            }
            break;
        }
    }
    notifyAbilityUse();
}
