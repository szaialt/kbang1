#include "cardmultishoot.h"
#include "gametable.h"
#include "gamecycle.h"
#include "game.h"
#include "player.h"
#include "gameexceptions.h"
#include "cardbarrel.h"

CardMultiShoot::CardMultiShoot(Game* game, int id, CardMultiShoot::Type type, CardSuit cardSuit, CardRank cardRank):
        ReactionCard(game, id, CARD_UNKNOWN, cardSuit, cardRank)
{
    switch(type) { 
    case Indians:
        setType(CARD_INDIANS);
        break;
    case Gatling: 
        setType(CARD_GATLING);
        break;
    case ManVsMachine:
        setType(CARD_MANN_VS_MACHINE);
        break;
    default:
        NOT_REACHED();
    }
    m_playedNextDirection = true;
}

void CardMultiShoot::play()
{
    gameCycle()->assertTurn();
      assertInHand();
      m_playedNextDirection = true;
      mp_shootingPlayer = owner();
      mp_requestedPlayer = owner();
      m_usedBarrels.clear();
      gameTable()->playerPlayCard(this);
      requestNext();
}

void CardMultiShoot::respondPass()
{
    gameCycle()->unsetResponseMode();
    gameTable()->playerPass(mp_requestedPlayer);
    bool injure = true;
    if (type() == CARD_INDIANS){
        QList<PlayingCard*> table = mp_requestedPlayer->table();
        foreach (PlayingCard* card, table){
            if (card->type() == CARD_PEACE_PIPE){
                injure = false;
            }
        }
    }
    if (injure){
        mp_requestedPlayer->modifyLifePoints(-1, mp_shootingPlayer);
    }
    if (m_playedNextDirection){
        requestNext();
    }
    else {
        requestPrevious();
    }
}

void CardMultiShoot::respondCard(PlayingCard* targetCard)
{
    Player* player = targetCard->owner();

    if (type() == CARD_INDIANS){
        QList<PlayingCard*> table = mp_requestedPlayer->table();
        foreach (PlayingCard* card, table){
            if (card->type() == CARD_PEACE_PIPE){
                game()->gameCycle().unsetResponseMode();
                if (m_playedNextDirection){
                     requestNext();
                }
                else {
                    requestPrevious();
               }
             return;
            }
        }
    }
    switch(targetCard->type()) {
        case CARD_BANG:
             if ((type() != CARD_INDIANS) && (type() != CARD_MANN_VS_MACHINE))
                 break;
             targetCard->assertInHand();
             gameTable()->playerRespondWithCard(targetCard);
             game()->gameCycle().unsetResponseMode();
             if (m_playedNextDirection){
                 requestNext();
             }
            else {
                requestPrevious();
             }
             return;
        case CARD_MISSED:
            if ((type() == CARD_INDIANS) || (type() == CARD_MANN_VS_MACHINE))
                 break;
            targetCard->assertInHand();
            gameTable()->playerRespondWithCard(targetCard);
            game()->gameCycle().unsetResponseMode();
            if (m_playedNextDirection){
                requestNext();
            }
            else {
                requestPrevious();
            }
            return;
        case CARD_BARREL: {
            if ((type() == CARD_INDIANS) || (type() == CARD_MANN_VS_MACHINE))
                 break;
            if (m_usedBarrels.contains(targetCard))
                break;
            targetCard->assertOnTable();
            m_usedBarrels.append(targetCard);
            CardBarrel* barrel = qobject_cast<CardBarrel*>(targetCard);
            barrel->check(this);
            return;
        }
        case CARD_DEAD_RINGER:
            if ((type() == CARD_INDIANS) || (type() == CARD_MANN_VS_MACHINE))
                 break;
            targetCard->assertInHand();
            gameTable()->playerRespondWithCard(targetCard);
            game()->gameCycle().unsetResponseMode();
            game()->gameCycle().setNeedsFinishTurn(true);
            if (m_playedNextDirection){
                requestNext();
            }
            else {
                requestPrevious();
            }
            return;
        case CARD_DEFLECTION:
            if ((type() == CARD_INDIANS) || (type() == CARD_MANN_VS_MACHINE))
                break;
            targetCard->assertInHand();
            respondWith(targetCard);
            //targetCard->play(owner());
            return;
            break;
        default:
            break;
        }
        throw BadCardException();

}

void CardMultiShoot::respondWith(PlayingCard* targetCard){
    gameTable()->playerRespondWithCard(targetCard);
    game()->gameCycle().unsetResponseMode();
    if (m_playedNextDirection){
         requestNext();
     }
    else {
        requestPrevious();
    }
}

void CardMultiShoot::checkResult(bool result)
{
    Q_ASSERT((type() != CARD_INDIANS) && (type() != CARD_MANN_VS_MACHINE));
    if (result) {
        game()->gameCycle().unsetResponseMode();
        if (m_playedNextDirection){
            requestNext();
        }
        else {
            requestPrevious();
        }
    }
}


ReactionType CardMultiShoot::reactionType() const
{
    if (type() == CARD_INDIANS)
        return REACTION_INDIANS;
    if (type() == CARD_MANN_VS_MACHINE)
        return REACTION_INDIANS;
    else if (type() == CARD_GATLING) 
        return REACTION_GATLING;
}

void CardMultiShoot::requestNext()
{
    mp_requestedPlayer = game()->nextPlayer(mp_requestedPlayer);
    if (mp_requestedPlayer == mp_shootingPlayer) return;
    game()->gameCycle().setResponseMode(this, mp_requestedPlayer);
}

void CardMultiShoot::requestPrevious()
{
    qDebug() << game()->previousPlayer(mp_requestedPlayer)->name();
    mp_requestedPlayer = game()->previousPlayer(mp_requestedPlayer);
    if (mp_requestedPlayer == mp_shootingPlayer) return;
    game()->gameCycle().setResponseMode(this, mp_requestedPlayer);
}
