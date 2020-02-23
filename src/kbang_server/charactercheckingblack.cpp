#include "charactercheckingblack.h"
#include "player.h"
#include "gamecycle.h"
#include "cardbang.h"
#include "gametable.h"
#include <algorithm>

CharacterCheckingBlack::CharacterCheckingBlack(QObject* parent, Type type):
        CharacterBase(parent, CHARACTER_UNKNOWN)
{
    m_used = false;
    switch(type) {
    case WilliamHarman:
        setCharacterType(CHARACTER_WILLIAM_HARMAN);
        break;
    case Clockwork:
        setCharacterType(CHARACTER_CLOCKWORK);
        break;
    }
}

void CharacterCheckingBlack::useAbility(){
    if ((characterType() == CHARACTER_CLOCKWORK) && (!m_used)){
        PlayingCard* checkedCard = gameTable().checkDeck();
        bool checkResult = check(checkedCard);
        if (checkResult){
            QList<Player*> list = mp_player->game()->playerList();
            std::reverse(list.begin(), list.end());
        }
        m_used = true;
        notifyAbilityUse();
    }
}

void CharacterCheckingBlack::useAbility(Player* targetPlayer)
{
    if ((characterType() == CHARACTER_WILLIAM_HARMAN) && (!m_used)){
    PlayingCard* checkedCard = gameTable().checkDeck();
    bool checkResult = check(checkedCard);
    if (checkResult){
        PlayingCard* targetCard = targetPlayer->getRandomCardFromHand();
        gameTable().playerStealCard(mp_player, targetCard);
    }
    m_used = true;
    notifyAbilityUse();
    }
}

bool CharacterCheckingBlack::check(PlayingCard* card)
{
    if (card->suit() == SUIT_SPADES) return true;
    if (card->suit() == SUIT_CLUBS) return true;
    return false;
}

void CharacterCheckingBlack::resetAbility(){
    m_used = false;
}
