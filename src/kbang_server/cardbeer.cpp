#include "cardbeer.h"
#include "player.h"
#include "gametable.h"
#include "gamecycle.h"
#include "game.h"
#include "gameexceptions.h"
#include "charactercassidygringo.h"
#include <iostream>

CardBeer::CardBeer(Game* game, int id, BeerType type, CardSuit cardSuit, CardRank cardRank):
        PlayingCard(game, id, CARD_UNKNOWN, cardSuit, cardRank),
        m_type(type)
{
    switch(m_type) {
    case Beer:
        setType(CARD_BEER);
        break;
    case Saloon:
        setType(CARD_SALOON);
        break;
    case Medicines:
        setType(CARD_MEDICINES);
        break;
    default:
        setType(CARD_UNKNOWN);
        break;
    }
}

CardBeer::~CardBeer()
{
}

CardColor CardBeer::color(){
    //Why does it belive that CARD_MEDICINES is brown?
    if (type() == CARD_MEDICINES) return COLOR_POSITIVE_GREY;
    if (type() == CARD_GREEN_ON_THE_HOUSE) return COLOR_GREEN;
    else return COLOR_BROWN;
}

void CardBeer::play()
{
      qDebug() << "CardBeer: pocket " << pocketTypeToString(pocket());
      qDebug() << "CardBeer: type " << playingCardTypeToString(type());
      gameCycle()->assertTurn();
      Player* player = owner();
      if (type() == CARD_BEER) {
          Player* player = owner();
              gameTable()->playerPlayCard(this);
              if (game()->alivePlayersCount() > 2){
                  player->modifyLifePoints(1, 0);
              }
          
      } 
      else if (type() == CARD_SALOON) {
        gameTable()->playerPlayCard(this);
        if (player->lifePoints() > 0){
            player->modifyLifePoints(1, 0);
        }
        for (Player* p = game()->nextPlayer(player);
             p != player;
             p = game()->nextPlayer(p)) {
            if (p->lifePoints() > 0){
                p->modifyLifePoints(1, 0);
            }
        }
      }
      else if (type() == CARD_MEDICINES) {
           playAsGreenCard();
      }
    
}

void CardBeer::takeGreenCardEffect(){
    /*if (owner()->lifePoints() == 0){
          throw BadUsageException();
    }*/
    if (type() == CARD_MEDICINES){
        owner()->modifyLifePoints(2, 0);
    }
    else throw BadUsageException();
}


BeerRescue::BeerRescue(Game* game):
        QObject(game),
        mp_game(game)
{
}

void BeerRescue::respondPass()
{
    bool last_saved = false;
    //Our operette
    if ((mp_game->gameInfo().ourFlag()) && !(mp_target->isCharmed()) && ((mp_target->character()->characterType() == CHARACTER_BART_CASSIDY) || (mp_target->character()->characterType() == CHARACTER_EL_GRINGO)) ){
        if (m_lifePointsToSave > 0){
          CharacterCassidyGringo* operetteCharacter = qobject_cast<CharacterCassidyGringo*>(mp_target->character());
        
          //An operettecharacter can use his ability even if he is dying
          if (mp_attacker){
            operetteCharacter->onHit(m_lifePointsToSave, mp_attacker);
          }
          else {
            operetteCharacter->onHit(m_lifePointsToSave);
          }
          QList<PlayingCard*> hand = mp_target->playerCtrl()->privatePlayerView().hand();
          foreach (PlayingCard* card, hand) {
            try {
              if (card->type() == CARD_BEER){
                mp_game->beerRescue()->respondCard(card);
                last_saved = true;
              }
            }
            catch (GameException& e) {
            
              e.debug();
            }
        }
        
      }
    }
    mp_game->gameCycle().unsetResponseMode();
    if (!last_saved){
      mp_target->lastSaveFailure(m_hitPoints, mp_attacker);
    }
}
 
void BeerRescue::respondCard(PlayingCard* targetCard)
{
    targetCard->assertInHand();
    
    if (targetCard->type() == CARD_BEER && mp_game->alivePlayersCount() > 2) {
        mp_game->gameTable().playerPlayCard(targetCard);
        dismiss();
        return;
    }
    //Our rules allows last save beer even with two players
    if (mp_game->gameInfo().ourFlag()){
        if ((targetCard->type() == CARD_BEER) && (mp_game->alivePlayersCount()  == 2)){
            if (m_lifePointsToSave > 0){
              mp_game->gameTable().playerPlayCard(targetCard);
              dismiss();
              return;
            }
            throw BadCardException();
        }
    }
    throw BadCardException();
}

void BeerRescue::dismiss()
{
    m_lifePointsToSave--;
    if (m_lifePointsToSave == 0) {
        mp_game->gameCycle().unsetResponseMode();
        mp_target->lastSaveSuccess(m_hitPoints, mp_attacker);
    }
}

void BeerRescue::allowSaveWithBeer(Player* attacker, Player* target, int lifePointsToSave, int hitPoints)
{
    mp_attacker = attacker;
    mp_target = target;

        m_lifePointsToSave = lifePointsToSave;
        m_hitPoints = hitPoints;
        mp_game->gameCycle().setResponseMode(this, mp_target);
    
}
