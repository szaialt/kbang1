#include "cardtaker.h"
#include "player.h"
#include "gamecycle.h"
#include "gametable.h"
#include "gameexceptions.h"
#include "game.h"
#include "cardbang.h"

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
    else if (m_type == DoublePanic)
        setType(CARD_DOUBLE_PANIC);
    else if (m_type == DoubleCatBalou)
        setType(CARD_DOUBLE_CATBALOU);
    
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
     if ((m_type == DoublePanic) || (m_type == DoubleCatBalou)){
        throw BadUsageException();
    }
    if (color() == COLOR_BROWN) {
        //qDebug() << "CardTaker play(Player* targetPlayer) 1";
      //qDebug() << "CardTaker play(Player* targetPlayer) 2";
      /* allow steel from himself only if has more than one card in hand */
      if (owner() == targetPlayer && owner()->handSize() < 2){
          //qDebug() << "CardTaker play(Player* targetPlayer) 3";
        throw BadCardException();
        //qDebug() << "CardTaker play(Player* targetPlayer) 4";
      }
      //qDebug() << "CardTaker play(Player* targetPlayer) 5";
      PlayingCard* targetCard;
      //qDebug() << "CardTaker play(Player* targetPlayer) 6";
      do {
          //qDebug() << "CardTaker play(Player* targetPlayer) 7";
        targetCard = targetPlayer->getRandomCardFromHand();
        //qDebug() << "CardTaker play(Player* targetPlayer) 8";
      } while ((targetCard == 0) || (targetCard == this)); // pick other than this card
      //qDebug() << "CardTaker play(Player* targetPlayer) 9";
      if (targetCard == 0){
        throw BadTargetPlayerException();
        //qDebug() << "CardTaker play(Player* targetPlayer) 10";
      }
      //qDebug() << "CardTaker play(Player* targetPlayer) 11";
      
      //qDebug() << "CardTaker play(Player* targetPlayer) 12";
      if ((type() == CARD_DOUBLE_PANIC) || (type() == CARD_DOUBLE_CATBALOU)){
          //if (targetPlayer->handSize() <= 1) {
              throw BadUsageException();
          //}
          /*PlayingCard* targetCard2 = targetPlayer->getRandomCardFromHand();
         do {
            //qDebug() << "CardTaker play(Player* targetPlayer) 7";
            targetCard2 = targetPlayer->getRandomCardFromHand();
            //qDebug() << "CardTaker play(Player* targetPlayer) 8";
        } while ((targetCard2 == 0) || (targetCard2 == this) || (targetCard2 == targetCard)); // pick other than this card
        //qDebug() << "CardTaker play(Player* targetPlayer) 9";
        if (targetCard2 == 0){
            throw BadTargetPlayerException();
            //qDebug() << "CardTaker play(Player* targetPlayer) 10";
       }
       QList<PlayingCard*> targetCards;
       targetCards.append(targetCard);
       targetCards.append(targetCard2);
       play(targetCards);
       */
      }
      else {
          play(targetCard);
    }

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
    if ((m_type == DoublePanic) || (m_type == DoubleCatBalou)){
        throw BadUsageException();
    }
    Player* o = owner();
    Player* targetPlayer = targetCard->owner();
    if (targetPlayer->characterType() == CHARACTER_JAREMY_BAILE){
        o->modifyLifePoints(-1, 0);
    }
    if (m_type == CatBalou) {
        //qDebug() << "CatBalou play(PlayingCard* targetCard) 1";
        //qDebug() << "CatBalou play(PlayingCard* targetCard) 2";
        gameCycle()->setCardEffect(1);
        //qDebug() << "CatBalou play(PlayingCard* targetCard) 3";
        gameTable()->playerPlayCard(this, targetCard);
        //qDebug() << "CatBalou play(PlayingCard* targetCard) 4";
        //We don't allow to force to discard Dynamite
        if ((targetCard != 0) && (targetCard->color() ==COLOR_DYNAMITE)){
            targetCard->play();
        }
        else {
            //qDebug() << "CatBalou play(PlayingCard* targetCard) 5";
            gameTable()->cancelCard(targetCard, o);
            //qDebug() << "CatBalou play(PlayingCard* targetCard) 6";
        }
        gameCycle()->setCardEffect(0);
        //qDebug() << "CatBalou play(PlayingCard* targetCard) 7";
    }
    else {
        if (m_type == Plunder) throw BadUsageException();
        if (m_type == BarFight) throw BadUsageException();
        if ((m_type == Pilfer) || (m_type == GreenFurTrade)){
            assertOnTable();
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
        Player* targetPlayer = targetCard->owner();
        if (targetPlayer->characterType() == CHARACTER_JAREMY_BAILE){
            o->modifyLifePoints(-1, 0);
        }
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
        if (targetPlayer->characterType() == CHARACTER_JAREMY_BAILE){
            o->modifyLifePoints(-1, 0);
        }
        gameCycle()->setCardEffect(0);
        
    }
    else throw BadUsageException();
}
    
void CardTaker::play(QList<PlayingCard*> targetCards){
    if (targetCards.size() < 2)  throw BadCardException();
    if ((m_type == DoublePanic) || (m_type == DoubleCatBalou)){
    gameCycle()->assertTurn();
    Player* o = owner();
    Player* targetPlayer1 = targetCards.at(0)->owner();
    Player* targetPlayer2 = targetCards.at(1)->owner();
    PlayingCard* targetCard1 = targetCards.at(0);
    PlayingCard* targetCard2 = targetCards.at(1);
    if ((targetPlayer1 != o) && targetCard1->pocket() == POCKET_HAND){
        throw BadUsageException();
        //targetCard1 = targetPlayer1->getRandomCardFromHand();
    }    
     if ((targetPlayer2 != o) && targetCard2->pocket() == POCKET_HAND){
         throw BadUsageException();
        //targetCard2 = targetPlayer2->getRandomCardFromHand();
    } 
    gameCycle()->setCardEffect(1);
    gameTable()->playerPlayCard(this);
    if (m_type == DoublePanic){
        gameTable()->playerStealCard(o,targetCard1);
        gameTable()->playerStealCard(o, targetCard2);
    }
    else if (m_type == DoubleCatBalou){
        gameTable()->playerDiscardCard(targetCard1);
        gameTable()->playerDiscardCard(targetCard2);
    }
    if (targetPlayer1->characterType() == CHARACTER_JAREMY_BAILE){
            o->modifyLifePoints(-1, 0);
        }
    if (targetPlayer2->characterType() == CHARACTER_JAREMY_BAILE){
            o->modifyLifePoints(-1, 0);
        }
    gameCycle()->setCardEffect(0);
    }
    else throw BadUsageException();
}
