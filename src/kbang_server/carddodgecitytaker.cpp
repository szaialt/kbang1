#include "carddodgecitytaker.h"
#include "player.h"
#include "gamecycle.h"
#include "gametable.h"
#include "gameexceptions.h"
#include "game.h"

CardDodgeCityTaker::CardDodgeCityTaker(Game* game, int id, CardTaker::CardTakerType type, CardSuit cardSuit, CardRank cardRank):
        CardTaker(game, id, CardTakerType::Panic, cardSuit, cardRank)
{
    switch(type) {
    case CanCan:
        setType(CARD_CAN_CAN);
        break; 
    case Conestoga:
        setType(CARD_CONESTOGA);
        break;
    case RagTime:
        setType(CARD_RAG_TIME);
        break;
    case Brawl:
        setType(CARD_BRAWL);
        break;
    default:
        NOT_REACHED();
    }
}

//Green cardtaker cause that you can keep less cards in hand
CardColor CardDodgeCityTaker::color() const {
    if (type() == CARD_CAN_CAN) return COLOR_GREEN;
    if (type() == CARD_CONESTOGA) return COLOR_GREEN;
    return COLOR_BROWN;
}

void CardDodgeCityTaker::play()
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

void CardDodgeCityTaker::play(PlayingCard* targetCard, Player* targetPlayer){
    if (type() == CARD_RAG_TIME){
      if (targetCard->owner() != owner()){
        throw BadUsageException(); 
      }
      if (targetCard->pocket() != POCKET_HAND){
        throw BadUsageException();
      }
      play(targetPlayer);
      if (targetCard->pocket() != POCKET_GRAVEYARD){
        gameTable()->playerDiscardCard(targetCard);
      }
    }
    else {
        throw BadUsageException();
    }
}

void CardDodgeCityTaker::play(Player* targetPlayer)
{
    //qDebug() << "CardTaker::play(Player* targetPlayer): " << pocketTypeToString(pocket());
    //qDebug() << "Pocket: " << pocketTypeToString(pocket());
    gameCycle()->assertTurn();
    if (color() == COLOR_BROWN) {
      assertInHand();
      /* allow steel from himself only if has more than one card in hand */
      if (owner() == targetPlayer && owner()->handSize() < 2){
        throw BadTargetPlayerException();
      }
      PlayingCard* targetCard;
      do {
        targetCard = targetPlayer->getRandomCardFromHand();
      } while ((targetCard != 0) && (targetCard == this)); // pick other than this card
      if (targetCard == 0){
        throw BadTargetPlayerException();
      }
      play(targetCard);
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

void CardDodgeCityTaker::play(PlayingCard* targetCard)
{
    //You must write this response into card types played with another card
    //to let Bandidos work correctly
    if (gameCycle()->isResponse()){
        gameTable()->playerDiscardCard(this);
        gameTable()->playerDiscardCard(targetCard);
    }
    else {
        gameCycle()->assertTurn();
    
        Player* o = owner();

        if (type() == CARD_BRAWL) {
            assertInHand();
            if (targetCard == 0){
                throw BadUsageException(); 
            }
            if (targetCard == this){
                throw BadUsageException(); 
            }
            if (targetCard->owner() != o){
                throw BadUsageException(); 
            }
            if (targetCard->pocket() != POCKET_HAND){
                throw BadUsageException();
            }
        
            gameTable()->playerPlayCard(this, targetCard);
            if (targetCard->pocket() != POCKET_GRAVEYARD){
                gameTable()->playerDiscardCard(targetCard); 
            }
            gameCycle()->setCardEffect(1);
            Player* targetPlayer;
            foreach (targetPlayer, game()->playerList()){
              if (targetPlayer == o) {
                  continue;
              }
              if (targetPlayer == 0) {
                  continue;
              }
              if (!targetPlayer->isAlive()) {
                  continue;
              }
              if (targetPlayer->handSize() == 0) {
                  continue;
              }
              PlayingCard* tCard = targetPlayer->getRandomCardFromHand();
              if (tCard == 0) continue;
              //We don't allow to force to discard Dynamite
              if ((tCard != 0) && (tCard->color() == COLOR_DYNAMITE)){
                 tCard->play();
              }
              else {
                if ((tCard != 0) && (tCard->pocket() != POCKET_GRAVEYARD))
                    gameTable()->playerDiscardCard(tCard);
                }
            }
            gameCycle()->setCardEffect(0); 
         
        }
        else {
            gameCycle()->setCardEffect(1);
            //We don't allow to force to discard Dynamite
            if (targetCard->color() == COLOR_DYNAMITE){
                targetCard->play();
            }
            else { 
                gameTable()->playerStealCard(o, targetCard);
            }
            gameTable()->playerDiscardCard(this);
            gameCycle()->setCardEffect(0); 
        } 
    }
}

void CardDodgeCityTaker::play(QList<PlayingCard*> targetCards)
{
    PlayingCard* targetCard = targetCards.first();
    targetCards.removeFirst();
    Player* o = owner();
    if (type() == CARD_BRAWL) {
        assertInHand();
        
        if (targetCard == 0){
          throw BadUsageException(); 
        }
        if (targetCard == this){ 
          throw BadUsageException(); 
        }
        if (targetCard->owner() != o){
          throw BadUsageException(); 
        }
        if (targetCard->pocket() != POCKET_HAND){
          throw BadUsageException();
        }
        
        bool targetsChecked = checkTargetCards(targetCards);
        if (targetsChecked){
            gameTable()->playerPlayCard(this, targetCard);
            if (targetCard->pocket() != POCKET_GRAVEYARD){
                gameTable()->playerDiscardCard(targetCard); 
            }
            foreach (PlayingCard* card, targetCards){
                if ((game()->gameInfo().ourFlag()) && (card->type() == CARD_DYNAMITE)){
                    card->play();
                }
                else {
                    if (card->pocket() != POCKET_GRAVEYARD){
                         gameCycle()->setCardEffect(1);
                         gameTable()->playerDiscardCard(card); 
                         gameCycle()->setCardEffect(0);
                    } 
                }
            }
        }
        //qDebug() << "Cardtaker BRAWL played."; 
    }
     else if (type() == CARD_RAG_TIME){
        assertInHand();
        if (targetCard == 0){
          throw BadUsageException(); 
        }
        if (targetCard == this){
          throw BadUsageException(); 
        }
        if (targetCard->owner() != o){
          throw BadUsageException(); 
        }
        if (targetCard->pocket() != POCKET_HAND){
          throw BadUsageException();
        }
        gameTable()->playerPlayCard(this, targetCard);
        if (targetCard->pocket() != POCKET_GRAVEYARD){
          gameTable()->playerDiscardCard(targetCard); 
        }
        gameTable()->playerStealCard(o, targetCards.first()); 
    }
    else {
        throw BadUsageException();
    }
}

bool CardDodgeCityTaker::checkTargetCards(QList<PlayingCard*> targetCards){
    QMap<Player*, PlayingCard*>  owners;
    foreach (PlayingCard* card, targetCards){
        Player* player = card->owner();
        if (owners.contains(player)) return false;
        owners.insert(player, card);
    }
    int numberOfOwners = owners.size();
    int empty = 0;
    foreach (Player* player, game()->playerList()){
        if (player->isAlive()){
           if (player->hand().empty()) {
              if (player->table().empty()){
                  empty++;
              }
           }
        }
    }
    qDebug() << empty;
    qDebug() << numberOfOwners;
    qDebug() << game()->alivePlayersCount() - 1;
    return (empty + numberOfOwners == game()->alivePlayersCount() - 1);
}
