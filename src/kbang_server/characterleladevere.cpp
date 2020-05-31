#include "characterleladevere.h"
#include "player.h"
#include "gamecycle.h"
#include "cardbang.h"
#include "cardmissed.h"
#include "reactionhandler.h"
#include "cardtakerbang.h"

CharacterLelaDevere::CharacterLelaDevere(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN)
       
{
    setCharacterType(CHARACTER_LELA_DEVERE);
}

void CharacterLelaDevere::useAbility(QList<PlayingCard*> cards){
    if (cards.size() < 2){
        throw BadCardException();
    }
    PlayingCard* card = cards.at(0);
    if (card->owner() != mp_player) throw BadCardException();
    PlayingCard* card2 = cards.at(1);
    ReactionCard* reactionCard = static_cast<ReactionCard*>(card);
    if (reactionCard == 0){
        throw new BadCardException();
    }
    bool canConvert = false;
    if (reactionCard->reactionType() == REACTION_BANG){
        canConvert = true;
    }
    else if (card->type() != CARD_INDIANS){
        canConvert = true; //Needed: to be converted to weakened Rissa
    }
    if (canConvert){
        PlayingCard* takerBang = new CardTakerBang(mp_player->game(), -1, SUIT_INVALID, 5);
        takerBang->setVirtual(card);
        takerBang->play(card2);
    }
    
    notifyAbilityUse();
} 

