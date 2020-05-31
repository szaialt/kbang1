#include "cardtaker.h"
#include "player.h"
#include "gamecycle.h"
#include "gametable.h"
#include "gameexceptions.h"
#include "game.h"

CardTaker::CardTaker(Game* game, int id, CardTaker::Type type, CardSuit cardSuit, CardRank cardRank):
        PlayingCard(game, id, CARD_UNKNOWN, cardSuit, cardRank),
        m_type(type)
{
    if (m_type == Panic)
        setType(CARD_PANIC);
    else if (m_type == CatBalou)
        setType(CARD_CATBALOU);
    else if (m_type == Pilfer)
        setType(CARD_PILFER);
    else if (m_type == GreenFurTrade)
        setType(CARD_GREEN_FUR_TRADE);
    else if (m_type == Plunder)
        setType(CARD_PLUNDER);
    else if (m_type == BarFight)
        setType(CARD_BAR_FIGHT);
    
}

CardTaker::~CardTaker()
{
}

CardColor CardTaker::color() const {
    if (type() == CARD_PILFER) return COLOR_GREEN;
    if (type() == CARD_GREEN_FUR_TRADE) return COLOR_GREEN;
    if (type() == CARD_PLUNDER) return COLOR_GREEN;
    if (type() == CARD_BAR_FIGHT) return COLOR_GREEN;
    return COLOR_BROWN;
}

void CardTaker::play()
{
    gameCycle()->assertTurn();
    if (color() == COLOR_GREEN) {
        //qDebug() << "CardTaker::play() CARD_CAN_CAN";
        Player* mt_owner = owner();
        playAsBlueCard();
        qDebug() << pocketTypeToString(pocket());
        //if (pocket() == POCKET_GRAVEYARD) {
        setPocket(POCKET_TABLE);
        setOwner(mt_owner);
        //}
    }
    else {
        //qDebug() << "CardTaker::play() 2";
        throw BadUsageException();
    }
}

void CardTaker::play(Player* targetPlayer)
{
    gameCycle()->assertTurn();
    
    if (color() == COLOR_BROWN) {
        qDebug() << "CatBalou play(Player* targetPlayer) 1";
      assertInHand();
      qDebug() << "CatBalou play(Player* targetPlayer) 2";
      /* allow steel from himself only if has more than one card in hand */
      if (owner() == targetPlayer && owner()->handSize() < 2){
          qDebug() << "CatBalou play(Player* targetPlayer) 3";
        throw BadTargetPlayerException();
        qDebug() << "CatBalou play(Player* targetPlayer) 4";
      }
      qDebug() << "CatBalou play(Player* targetPlayer) 5";
      PlayingCard* targetCard;
      qDebug() << "CatBalou play(Player* targetPlayer) 6";
      do {
          qDebug() << "CatBalou play(Player* targetPlayer) 7";
        targetCard = targetPlayer->getRandomCardFromHand();
        qDebug() << "CatBalou play(Player* targetPlayer) 8";
      } while ((targetCard == 0) || (targetCard == this)); // pick other than this card
      qDebug() << "CatBalou play(Player* targetPlayer) 9";
      if (targetCard == 0){
        throw BadTargetPlayerException();
        qDebug() << "CatBalou play(Player* targetPlayer) 10";
      }
      qDebug() << "CatBalou play(Player* targetPlayer) 11";
      play(targetCard);
      qDebug() << "CatBalou play(Player* targetPlayer) 12";
    } 
    else {
      if (pocket() == POCKET_TABLE) {
        setAct(false);
        if (targetPlayer == owner()){
          throw BadTargetPlayerException();
        }
          PlayingCard* targetCard;
        do {
          targetCard = targetPlayer->getRandomCardFromHand();
        } while ((targetCard != 0) && (targetCard == this)); // pick other than this card
        if (targetCard == 0){
          throw BadTargetPlayerException();
        }
        Player* t_owner = owner();
        play(targetCard);
        setPocket(POCKET_TABLE);
        setOwner(t_owner);          
      }
    }
    
}

void CardTaker::play(PlayingCard* targetCard)
{
    gameCycle()->assertTurn();
    
    Player* o = owner();
    //Player* targetPlayer = targetCard->owner();
 
    
    if (m_type == CatBalou) {
        qDebug() << "CatBalou play(PlayingCard* targetCard) 1";
        assertInHand();
        qDebug() << "CatBalou play(PlayingCard* targetCard) 2";
        gameCycle()->setCardEffect(1);
        qDebug() << "CatBalou play(PlayingCard* targetCard) 3";
        gameTable()->playerPlayCard(this, targetCard);
        qDebug() << "CatBalou play(PlayingCard* targetCard) 4";
        //We don't allow to force to discard Dynamite
        if ((targetCard != 0) && (targetCard->color() ==COLOR_DYNAMITE)){
            targetCard->play();
        }
        else {
            qDebug() << "CatBalou play(PlayingCard* targetCard) 5";
            gameTable()->cancelCard(targetCard, o);
            qDebug() << "CatBalou play(PlayingCard* targetCard) 6";
        }
        gameCycle()->setCardEffect(0);
        qDebug() << "CatBalou play(PlayingCard* targetCard) 7";
    }
    else {
        if (m_type == Plunder) throw BadUsageException();
        if (m_type == BarFight) throw BadUsageException();
        if ((m_type == Pilfer) || (m_type == GreenFurTrade)){
            assertOnTable();
        }
        else if (m_type == Panic){
            assertInHand();
        }
        if (m_type != GreenFurTrade) {
            /* distance check */ 
            if (game()->getDistance(owner(), targetCard->owner()) > 1){
                throw PlayerOutOfRangeException();
            }
        }
        
        gameCycle()->setCardEffect(1);
        gameTable()->playerPlayCard(this, targetCard); 
        gameTable()->playerStealCard(o, targetCard);
        //We force to play stolen Dynamite 
        if ((targetCard != 0) && (targetCard->color() == COLOR_DYNAMITE)){
            targetCard->play();
        }
        if (m_type == GreenFurTrade){
            gameTable()->playerDrawFromDeck(o, 2);
        }
        gameCycle()->setCardEffect(0);
        
    } 
}

void CardTaker::play(PlayingCard* targetCard, Player* targetPlayer){           
    if ( ((type() == CARD_PLUNDER) && (pocket() == POCKET_TABLE))
       || ((type() == CARD_BAR_FIGHT) && (pocket() == POCKET_TABLE)) ) {
        if (targetCard->owner() != owner()) throw BadCardException();
        if (targetPlayer->hand().isEmpty()) throw BadTargetPlayerException();
        Player* o = owner();
        gameCycle()->setCardEffect(1);
        gameTable()->playerPlayCard(this);
        gameTable()->playerDiscardCard(targetCard);
        PlayingCard* card = targetPlayer->getRandomCardFromHand();
        if (type() == CARD_PLUNDER) {
            gameTable()->playerStealCard(o, card);
        }
        else {
            gameTable()->cancelCard(card, o);
        }
        gameCycle()->setCardEffect(0);
    }
    else throw BadUsageException();
}
    
