#include "characterernestsaliven2.h"
#include "gametable.h"
#include "player.h"
#include "gameexceptions.h"
#include "carddrawcards.h"

CharacterErnestSaliven2::CharacterErnestSaliven2(QObject* parent):
        CharacterBase(parent, CHARACTER_ERNEST_SALIVEN2)
{
    m_canUseAbility = true;
}


void CharacterErnestSaliven2::useAbility(QList<PlayingCard*> cards){
    if (cards.empty()) throw BadCardException();
    PlayingCard* card = cards.at(0);
    if (card->owner() != mp_player) throw BadCardException();
    if (card->pocket() != POCKET_HAND) throw BadCardException();
    if (card->color() != COLOR_BLUE) throw BadCardException();
    
    PlayingCard* aceUp = new CardDrawCards(mp_player->game(), -1, CardDrawCards::AceUpYourSleeve, card->suit(), card->rank());
    aceUp->setVirtual(card);
    aceUp->play();
    notifyAbilityUse();
    
    m_canUseAbility = false;
}

void CharacterErnestSaliven2::resetAbility(){
    m_canUseAbility = true;
}
