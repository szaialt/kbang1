#include "charactermaggiemae.h"
#include "playingcard.h"
#include "player.h"
#include "gametable.h"

CharacterMaggieMae::CharacterMaggieMae(QObject* parent):
        CharacterBase(parent, CHARACTER_MAGGIE_MAE),
        m_canUseAbility(false)
{
}

void CharacterMaggieMae::draw(bool specialDraw){
    mp_player->game()->gameTable().playerDrawFromDeck(mp_player, 1, 0);
    QList<PlayingCard*> cards = mp_player->game()->gameTable().playerDrawFromDeck(mp_player, 1, 1);
    PlayingCard* card = cards[0];
    Q_ASSERT(card != 0);
    if (card->rank() > 10) {
        notifyAbilityUse();
        m_canUseAbility = true;
        mp_player->game()->gameTable().playerDrawFromDeck(mp_player, 1, 0);
    }
}

void CharacterMaggieMae::useAbility(QList<PlayingCard*> cards){
    if (!m_canUseAbility) throw new BadUsageException();
    if (cards.empty()) throw new BadUsageException();
    
    PlayingCard* targetCard1 = cards.at(0);
    PlayingCard* targetCard2 = cards.at(1);
    Player* player1 = targetCard1->owner();
    Player* player2 = targetCard2->owner();
    
    mp_player->game()->gameTable().playerStealCard(player2, targetCard1);
    mp_player->game()->gameTable().playerStealCard(player1, targetCard2);
        
    m_canUseAbility = false;
    
}
