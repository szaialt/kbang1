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
    case BrownShowTime:
        setType(CARD_BROWN_SHOW_TIME);
        break;
    case WarParty:
        setType(CARD_WAR_PARTY);
        break;
    case Roulette:
        setType(CARD_ROULETTE);
        break;
    case WeakenedBrawl:
        setType(CARD_LELA_GATLING);
        break;
    default:
        NOT_REACHED();
    }
    m_playedNextDirection = true;
}

CardColor CardMultiShoot::color() const{
    if (type() == CARD_WAR_PARTY)
        return COLOR_GREEN;
    if (type() == CARD_ROULETTE)
        return COLOR_GREEN;
    return COLOR_BROWN;
}

void CardMultiShoot::play()
{
    gameCycle()->assertTurn();
      if ((color() == COLOR_GREEN) && (pocket() == POCKET_HAND)){
          playAsBlueCard();
          return;
      }
      if (color() != COLOR_BROWN){
          assertOnTable();
      }
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
    if (mp_shootingPlayer == mp_requestedPlayer) {
        gameTable()->playerPass(mp_requestedPlayer);
    }
    else {
        gameTable()->playerPass(mp_requestedPlayer);
    }
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
        if (type() == CARD_ROULETTE) return;
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

    if (type() == CARD_INDIANS){
        QList<PlayingCard*> table = mp_requestedPlayer->table();
        foreach (PlayingCard* card, table){
            if (card->type() == CARD_PEACE_PIPE){
                game()->gameCycle().unsetResponseMode();
                requestNext();
             return;
                
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
    if (type() == CARD_LELA_GATLING){
        gameTable()->playerRespondWithCard(targetCard);
        game()->gameCycle().unsetResponseMode();
        if (m_playedNextDirection){
            requestNext();
        }
        else {
            requestPrevious();
        }
        return;
    }
    switch(targetCard->type()) {
        case CARD_BANG:
        case CARD_UNLIMITED_BANG:
             if ((type() != CARD_INDIANS) && (type() != CARD_MANN_VS_MACHINE) && (type() != CARD_WAR_PARTY))
                 break;
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
            if ((type() == CARD_INDIANS) || (type() == CARD_MANN_VS_MACHINE) || (type() == CARD_WAR_PARTY))
                 break;
            if (type() == CARD_BROWN_SHOW_TIME)
                break;
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
            //if ((type() == CARD_INDIANS) || (type() == CARD_MANN_VS_MACHINE) || (type() == CARD_WAR_PARTY))
            //     break;
            //if (type() == CARD_BROWN_SHOW_TIME)
            //    break;
            if (m_usedBarrels.contains(targetCard))
                break;
            targetCard->assertOnTable();
            m_usedBarrels.append(targetCard);
            CardBarrel* barrel = qobject_cast<CardBarrel*>(targetCard);
            barrel->check(this);
            break;
        }
        case CARD_DEAD_RINGER:
            if ((type() == CARD_INDIANS) || (type() == CARD_MANN_VS_MACHINE) || (type() == CARD_WAR_PARTY))
                 break;
            if (type() == CARD_BROWN_SHOW_TIME)
                break;
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
            if ((type() == CARD_INDIANS) || (type() == CARD_MANN_VS_MACHINE) || (type() == CARD_WAR_PARTY))
                break;
            if (type() == CARD_BROWN_SHOW_TIME)
                break;
            respondWith(targetCard);
            if (m_playedNextDirection){
                requestNext();
            }
            else {
                requestPrevious();
            }
            return;
        case CARD_VEST:
            if ((type() == CARD_INDIANS) || (type() == CARD_MANN_VS_MACHINE) || (type() == CARD_WAR_PARTY))
                 break;
            if (type() == CARD_BROWN_SHOW_TIME)
                break;
             targetCard->assertOnTable();
             respondWith(targetCard);
            if (m_playedNextDirection){
                requestNext();
            }
            else {
                requestPrevious();
            }
            return;
            //You neeed enumerate all weapons there.
        case CARD_VOLCANIC:
        case CARD_SCHOFIELD:
        case CARD_REMINGTON:
        case CARD_CARABINE:
        case CARD_WINCHESTER:
        case CARD_GUITAR:
        case CARD_HALF_ZATOCHI:
        case CARD_MEDI_GUN:
        case CARD_SANDMAN:
        case CARD_SHOTGUN:
        case CARD_WALKER:
        case CARD_BULLDOG_1:
            if (type() != CARD_BROWN_SHOW_TIME)
                break;
            gameTable()->playerRespondWithCard(targetCard);
            game()->gameCycle().unsetResponseMode();
            if (m_playedNextDirection){
                requestNext();
            }
            else {
                requestPrevious();
            }
            return;
        default:{
            if ((type() == CARD_INDIANS) || (type() == CARD_MANN_VS_MACHINE) || (type() == CARD_WAR_PARTY)){
            QList<PlayingCard*> table = targetCard->owner()->table();
            foreach (PlayingCard* card, table){
            if (card->type() == CARD_STEROID){
                respondWith(targetCard);
                return;
                break;
                if (m_playedNextDirection){
                    requestNext();
                }
                else {
                    requestPrevious();
                }
                return;
            }
        }
        break;
        
        } 
        }
        break;

    }
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
    if (type() == CARD_WAR_PARTY)
        return REACTION_INDIANS;
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
