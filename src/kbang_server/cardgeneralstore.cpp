#include "cardgeneralstore.h"
#include "gametable.h"
#include "gamecycle.h"
#include "game.h"
#include "gameexceptions.h"
#include "characterchosingthomas.h"

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
    if (type() == CARD_GENERALSTORE){
        gameTable()->playerPlayCard(this);
        gameTable()->drawIntoSelection(game()->alivePlayersCount());
    }
    else if (type() == CARD_ROB_GRAVE){
     gameTable()->drawGraveyardIntoSelection(game()->alivePlayersCount());
     gameTable()->playerPlayCard(this);
    }
    m_remained = game()->alivePlayersCount();
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
        mp_currentPlayer = game()->nextPlayer(mp_currentPlayer);
        if ((game()->nextPlayer(mp_currentPlayer) == mp_firstPlayer)
            ||((m_remained == 1) && (mp_currentPlayer == mp_firstPlayer))
        ) {
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
