#include "cardgeneralstore.h"
#include "gametable.h"
#include "gamecycle.h"
#include "game.h"
#include "gameexceptions.h"
#include "characterchosingthomas.h"
#include "charactertucoelfeo.h"

CardGeneralStore::CardGeneralStore(Game* game, int id, Type type, CardSuit cardSuit, CardRank cardRank):
        ReactionCard(game, id, CARD_GENERALSTORE, cardSuit, cardRank),
        m_type(type),
        m_remained(0)
{
    switch(m_type) {
    case GeneralStore:
        setType(CARD_GENERALSTORE);
        break;
    case RobGrave:
        setType(CARD_ROB_GRAVE);
        break;
    }
}

CardGeneralStore::~CardGeneralStore()
{
}

void CardGeneralStore::play()
{
    gameCycle()->assertTurn();
    
    mp_firstPlayer = owner();
    gameCycle()->setCardEffect(1);
    mp_currentPlayer = 0;
    m_remained = game()->alivePlayersCount();
    m_remained = m_remained + calculateBruceLings();
    if (type() == CARD_GENERALSTORE){
        Player* player = owner();
        foreach (player, game()->playerList()){
            if (player->characterType() == CHARACTER_TUCO_EL_FEO){
              CharacterTucoElFeo* tuco =  qobject_cast<CharacterTucoElFeo*>(player->character());
              tuco->resetAbility();
            }
        }
        gameTable()->playerPlayCard(this);
        gameTable()->drawIntoSelection(m_remained);
    }
    else if (type() == CARD_ROB_GRAVE){
     gameTable()->drawGraveyardIntoSelection(game()->alivePlayersCount());
     gameTable()->playerPlayCard(this);
    }
    requestNext();
}

void CardGeneralStore::respondPass(){
    game()->gameCycle().unsetResponseMode();
    if ((type() == CARD_GENERALSTORE) && (mp_currentPlayer->characterType() == CHARACTER_CHOSING_THOMAS)){
        CharacterChosingThomas* thomas =  qobject_cast<CharacterChosingThomas*>(mp_currentPlayer->character());
        if (thomas->canUseAbility()){
            gameTable()->cancelSelection();
            gameTable()->drawIntoSelection(m_remained-1);
            thomas->abilityUsed();
        }
    }
    gameTable()->playerPass(mp_currentPlayer);
    requestNext();
}

void CardGeneralStore::respondCard(PlayingCard* targetCard)
{
    if (targetCard->pocket() != POCKET_SELECTION)
        throw BadCardException();
    gameTable()->playerPickFromSelection(mp_currentPlayer,targetCard);
    game()->gameCycle().unsetResponseMode();
    requestNext();
}


void CardGeneralStore::requestNext()
{
    m_remained--;
    if (m_remained < 0) m_remained = 0;
    if (mp_currentPlayer == 0) {
        mp_currentPlayer = mp_firstPlayer;
    } else {
         if  ((type() == CARD_GENERALSTORE) && (mp_currentPlayer->characterType() == CHARACTER_TUCO_EL_FEO)){
           CharacterTucoElFeo* tuco =  qobject_cast<CharacterTucoElFeo*>(mp_currentPlayer->character());
           if (tuco->items() == tuco->itemNumber){
              tuco->itemToken();
          }
          else {
              tuco->itemToken();
             mp_currentPlayer = game()->nextPlayer(mp_currentPlayer);
            }
         }
        else {
           mp_currentPlayer = game()->nextPlayer(mp_currentPlayer);
        }
        if (isLastCard())
         {
            qDebug() << "Size of the selection is " << gameTable()->selection().size();
            if (gameTable()->selection().size() == 0){
                gameCycle()->setCardEffect(0);
                return;
            }
            //Q_ASSERT(gameTable()->selection().size() == 1);
            PlayingCard* selectionCard = gameTable()->selection()[0];
            gameTable()->playerPickFromSelection(mp_currentPlayer, selectionCard);
            gameCycle()->setCardEffect(0);
            return;
        }
    }
    game()->gameCycle().setResponseMode(this, mp_currentPlayer);
}

bool CardGeneralStore::isLastCard(){
    if (mp_currentPlayer->characterType() == CHARACTER_TUCO_EL_FEO){
        if (m_remained == 0) return true;
        CharacterTucoElFeo* tuco =  qobject_cast<CharacterTucoElFeo*>(mp_currentPlayer->character());
        if (tuco->items() == 0){
            if ((m_remained == 1) && (mp_currentPlayer == mp_firstPlayer)) {return true;}
        }
        {return false;}
    }
    if (game()->nextPlayer(mp_currentPlayer) == mp_firstPlayer) {return true;}
    if ((m_remained == 1) && (gameTable()->selection().size() == 1) && (mp_currentPlayer == mp_firstPlayer)) {return true;}
    return false;
}

int CardGeneralStore::calculateBruceLings(){
    int tucos = 0;
    Player* player;
    foreach (player, game()->playerList()){
        if (player->isAlive()) {
          if (player->characterType() == CHARACTER_TUCO_EL_FEO){
            tucos++;
          }
        }
    }
    return tucos;
}
