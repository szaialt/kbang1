#include "charactertimcroupier.h"
#include "gametable.h"
#include "playingcard.h"

CharacterTimCroupier::CharacterTimCroupier(QObject* parent):
        CharacterBase(parent, CHARACTER_TIM_CROUPIER)
{
}

void CharacterTimCroupier::draw(bool)
{
    m_cards = gameTable().playerDrawFromDeck(mp_player, 2, 0);
    notifyAbilityUse();
}

void CharacterTimCroupier::useAbility() {
    if (m_cards.at(0)->pocket() != POCKET_HAND){
        throw BadCardException();
    }
    if (m_cards.at(0)->owner() != mp_player){
        throw BadCardException();
    }
    if (m_cards.at(1)->pocket() != POCKET_HAND){
        throw BadCardException();
    }
    if (m_cards.at(1)->owner() != mp_player){
        throw BadCardException();
    }
    gameTable().playerDiscardCard(m_cards.at(0));
    gameTable().playerDiscardCard(m_cards.at(1));
    gameTable().playerDrawFromDeck(mp_player, 2, 0);
    notifyAbilityUse();
}
