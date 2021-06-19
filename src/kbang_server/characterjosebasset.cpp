#include "characterjosebasset.h"
#include "playingcard.h"

CharacterJoseBasset::CharacterJoseBasset(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_JOSEY_BASSET);
  m_canUseAbility = true;
}

// She can get chards if she didn't played any chard 

     void CharacterJoseBasset::playCard(PlayingCard* card){
        card->play();
        m_canUseAbility = false;
    }
    
     void CharacterJoseBasset::playCard(PlayingCard* card, Player* targetPlayer){
        card->play(targetPlayer);
        m_canUseAbility = false;
    }
    
     void CharacterJoseBasset::playCard(PlayingCard* card, PlayingCard* targetCard){
        card->play(targetCard);
        m_canUseAbility = false;
    }
    
     void CharacterJoseBasset::playCard(PlayingCard* card, PlayingCard* targetCard, Player* targetPlayer){
        card->play(targetCard, targetPlayer);
        m_canUseAbility = false;
    }
    
     void CharacterJoseBasset::playCard(PlayingCard* card, QList<PlayingCard*> targetCards){
        card->play(targetCards);
        m_canUseAbility = false;
    }

bool CharacterJoseBasset::canGetCards(){
    return m_canUseAbility;
}
    
void CharacterJoseBasset::resetAbility(){
    m_canUseAbility = true;
}
