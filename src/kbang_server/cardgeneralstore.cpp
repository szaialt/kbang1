#include "cardgeneralstore.h"
#include "gametable.h"
#include "gamecycle.h"
#include "game.h"
#include "gameexceptions.h"

CardGeneralStore::CardGeneralStore(Game* game, int id, Type type, CardSuit cardSuit, CardRank cardRank):
        ReactionCard(game, id, CARD_GENERALSTORE, cardSuit, cardRank),
        m_type(type)
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
    assertInHand();
    mp_firstPlayer = owner();
    gameCycle()->setCardEffect(1);
    mp_currentPlayer = 0;
    if (type() == CARD_GENERALSTORE){
        gameTable()->playerPlayCard(this);
        gameTable()->drawIntoSelection(game()->alivePlayersCount());
    }
    else if (type() == CARD_ROB_GRAVE){
     gameTable()->drawGraveyardIntoSelection(game()->alivePlayersCount());
     gameTable()->playerPlayCard(this);
    }
    requestNext();
}

void CardGeneralStore::respondPass(){
    game()->gameCycle().unsetResponseMode();
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
    if (mp_currentPlayer == 0) {
        mp_currentPlayer = mp_firstPlayer;
    } else {
        mp_currentPlayer = game()->nextPlayer(mp_currentPlayer);
        if (game()->nextPlayer(mp_currentPlayer) == mp_firstPlayer) {
            qDebug() << "Size of the selection is " << gameTable()->selection().size();
            if (gameTable()->selection().size() == 0){
                gameCycle()->setCardEffect(0);
                return;
            }
            Q_ASSERT(gameTable()->selection().size() == 1);
            PlayingCard* selectionCard = gameTable()->selection()[0];
            gameTable()->playerPickFromSelection(mp_currentPlayer, selectionCard);
            gameCycle()->setCardEffect(0);
            return;
        }
    }
    game()->gameCycle().setResponseMode(this, mp_currentPlayer);
}
