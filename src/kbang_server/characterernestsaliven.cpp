#include "characterernestsaliven.h"
#include "gametable.h"
#include "player.h"
#include "gameexceptions.h"
#include "gamecycle.h"

CharacterErnestSaliven::CharacterErnestSaliven(QObject* parent):
        CharacterBase(parent, CHARACTER_ERNEST_SALIVEN)
{
    m_canUseAbility = true;
}


void CharacterErnestSaliven::useAbility(QList<PlayingCard*> cards){
    if (cards.empty()) throw BadCardException();
    PlayingCard* card = cards.at(0);
    if (card->owner() != mp_player) throw BadCardException();
    if (card->pocket() != POCKET_HAND) throw BadCardException();
    if (card->color() != COLOR_BLUE) throw BadCardException();
    
    QList<PlayingCard*> drawedCards = gameTable().playerDrawFromDeck(mp_player, 2, 0);
    gameTable().undrawCard(card);
    gameTable().undrawCard(drawedCards.at(0));
    
    notifyAbilityUse();
    m_canUseAbility = false;
}

void CharacterErnestSaliven::resetAbility(){
    m_canUseAbility = true;
}
