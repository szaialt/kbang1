#include "carddrawcards.h"
#include "gametable.h"
#include "gamecycle.h"

CardDrawCards::CardDrawCards(Game* game, int id, CardDrawCards::Type type, CardSuit cardSuit, CardRank cardRank):
        PlayingCard(game, id, CARD_UNKNOWN, cardSuit, cardRank),
        m_type(type)
{
    switch(m_type) {
    case Diligenza:
        setType(CARD_DILIGENZA);
        m_cardCount = 2;
        break;
    case WellsFargo:
        setType(CARD_WELLSFARGO);
        m_cardCount = 3;
        break;
    case SupplyCrate:
        setType(CARD_SUPPLY_CRATE);
        m_cardCount = 3;
        break;
    }
}


CardDrawCards::~CardDrawCards()
{
}

CardColor CardDrawCards::color() const {
    return COLOR_BROWN;
}

void CardDrawCards::play()
{
    gameCycle()->assertTurn();
    if (type() == CARD_SUPPLY_CRATE){
        throw BadUsageException();
    }
    else {
      assertInHand();
      Player* player = owner();
      gameCycle()->setCardEffect(1);
      gameTable()->playerPlayCard(this);
      gameTable()->playerDrawFromDeck(player, m_cardCount);
      gameCycle()->setCardEffect(0); 
    }
}

void CardDrawCards::play(PlayingCard* targetCard){
    if (type() == CARD_SUPPLY_CRATE){
      if (targetCard->owner() != owner())
            throw BadUsageException();  
        if (targetCard->pocket() != POCKET_HAND)
            throw BadUsageException();
      assertInHand();
      Player* player = owner();
      gameCycle()->setCardEffect(1);
      gameTable()->playerPlayCard(this);
      gameTable()->playerDrawFromDeck(player, m_cardCount);
      gameCycle()->setCardEffect(0); 
      if (targetCard->pocket() != POCKET_GRAVEYARD)
        gameTable()->playerDiscardCard(targetCard);
    }
    else throw BadUsageException();
}

