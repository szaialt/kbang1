#include "voidai.h"
#include "playerctrl.h"
#include "publicgameview.h"
#include "privateplayerview.h"
#include "cards.h"
#include "util.h"

#include <QDebug>
#include <QTimer>
#include <QApplication>
#include <cstdlib>

int VoidAI::sm_playerCounter = 0;

int minActionDelay = 200;
int maxActionDelay = 1500;
 

     void VoidAI::onPlayerDied(PublicPlayerView&, PublicPlayerView*) {
    }
    
     void VoidAI::onPlayerDied(PublicPlayerView&) {
    }

VoidAI::VoidAI(QObject* parent):
        QObject(parent),
        m_id(++sm_playerCounter)
{
    //moveToThread(QApplication::instance()->thread());
}

CreatePlayerData VoidAI::createPlayerData() const
{
    CreatePlayerData res;
    res.name = QString("VoidAI #%1").arg(m_id);
    res.password = "void";
    return res;
}

void VoidAI::onHandlerRegistered(const PublicGameView* publicGameView, PlayerCtrl* playerCtrl)
{
    mp_playerCtrl = playerCtrl;
}

void VoidAI::onActionRequest(ActionRequestType requestType)
{
    m_requestType = requestType;
    //int randomDelay = (rand() % (maxActionDelay - minActionDelay)) + minActionDelay;
    QTimer::singleShot(200, this, SLOT(requestWithAction()));
}

void VoidAI::requestWithAction()
{
    qDebug() << QString("VoidAI (%1): onActionRequest(%2)").arg(m_id).arg(m_requestType);
    if (mp_playerCtrl->publicGameView().gameContextData().requestedPlayerId != mp_playerCtrl->privatePlayerView().id()) {
        QString("VoidAI (%1): Not requested!").arg(m_id);
        return;
    }
    QList<PlayingCard*> hand = mp_playerCtrl->privatePlayerView().hand();
    switch(m_requestType) {
        case REQUEST_DRAW:
        qDebug() << QString("VoidAI (%1): REQUEST_DRAW").arg(m_id);
            // Drawing two cards
            try {
                mp_playerCtrl->draw();
            } catch (BadPredrawException& e) {
                e.debug();
                QList<PlayingCard*> table = mp_playerCtrl->privatePlayerView().table();
                foreach(PlayingCard* c, table) {
                    try {
                        qDebug() << "Trying to play some card to bypass predraw exception";
                        if ((c->color() == COLOR_BLUE) || (c->color() == COLOR_DYNAMITE)){ 
                          try {
                            mp_playerCtrl->playCard(c);
                            return;
                          }
                          catch (BadPredrawException& e) {
                              e.debug(); 
                          }
                          catch (GameException& e) {
                              e.debug();
                          }
                        }
                    } catch (GameException& e) {
                        qDebug() << "Predraw exception test exception:";
                        e.debug();
                    }
                }
            }
            break;
        case REQUEST_PLAY: {
            qDebug() << QString("VoidAI (%1): REQUEST_PLAY").arg(m_id);
            // Try to use green cards:
            QList<PlayingCard*> table = mp_playerCtrl->privatePlayerView().table();
            // Try to use blue cards:
            foreach (PlayingCard* card, hand) {
                try {
                    switch(card->type()) {
                        case CARD_APPALOSSA:
                        case CARD_MUSTANG:
                        case CARD_VOLCANIC:
                        case CARD_SCHOFIELD:
                        case CARD_REMINGTON:
                        case CARD_CARABINE:
                        case CARD_WINCHESTER:
                        case CARD_DILIGENZA:
                        case CARD_WELLSFARGO:
                        case CARD_INDIANS:
                        case CARD_GATLING:
                        case CARD_GENERALSTORE:
                        case CARD_DYNAMITE:
                        case CARD_BARREL:
                        case CARD_MANN_VS_MACHINE:
                        case CARD_HALF_ZATOCHI:
                        case CARD_MEDI_GUN:
                        case CARD_SANDMAN:
                        case CARD_PERSUASION:
                        {
                            mp_playerCtrl->playCard(card);
                            return;
                        }
                        case CARD_BEER:
                        case CARD_MAD_MILK:
                        case CARD_SANDVICH: 
                        { 
                            if (mp_playerCtrl->privatePlayerView().lifePoints() <
                                    mp_playerCtrl->privatePlayerView().maxLifePoints()) {
                                mp_playerCtrl->playCard(card);
                                return;
                                }
                            }
                        default:
                            break;
                    }
                } catch (BadCardException e) {
                    qDebug() << "VoidAI: BadCardException!";
                } catch (BadUsageException e) {
                    qDebug() << "VoidAI: BadUsageException!";
                } catch (GameException& e)  {
                    qDebug() << "VoidAI: (checkpoint #1)";
                    e.debug();
                }
            }
             foreach (PlayingCard* card, hand) {
                 try {
                     switch(card->type()) {
                         case CARD_BANG:
                         case CARD_DUEL:
                         case CARD_JAIL:
                         case CARD_PANIC:
                         case CARD_CATBALOU:
                         case CARD_DIRECT_HIT:
                         case CARD_GUITAR:
                         case CARD_JARATE:
                         {
                             QList<PublicPlayerView*> players = mp_playerCtrl->publicGameView().publicPlayerList();
                             shuffleList(players);
                             foreach(const PublicPlayerView* p, players) {
                                 if (mp_playerCtrl->privatePlayerView().id() == p->id()) {
                                     continue;
                                 }
                                 try {
                                     mp_playerCtrl->playCard(card, p);
                                     return;
                                 } catch (BadTargetPlayerException e) {
                                     qDebug() << "VoidAI: BadTargetPlayerException!";
                                 } catch (BadCardException e) {
                                     qDebug() << "VoidAI: BadCardException!";
                                 } catch (BadUsageException e) {
                                     qDebug() << "VoidAI: BadUsageException!";
                                 } catch (OneBangPerTurnException e) {
                                     qDebug() << "VoidAI: One bang per turn!";
                                 } catch(GameException& e) {
                                     qDebug() << "VoidAI: GameException";
                                 }
                             }
                             break;
                         }
                         case CARD_SUPPLY_CRATE:
                             { 
                             QList<PublicPlayerView*> players = mp_playerCtrl->publicGameView().publicPlayerList();
                             shuffleList(players);
                             foreach(const PublicPlayerView* p, players) {
                                 if (mp_playerCtrl->privatePlayerView().id() == p->id()) {
                                     continue;
                                 }
                                 try {
                                        mp_playerCtrl->playCard(card, mp_playerCtrl->getRandomCardFromHand());
                                        return;
                                 } catch (BadUsageException e) {
                                    
                                    qDebug() << "VoidAI: BadUsageException!";
                                 } catch (BadTargetPlayerException e) {
                                     qDebug() << "VoidAI: BadTargetPlayerException!";
                                 } 
                                 catch (BadCardException e) {
                                     qDebug() << "VoidAI: BadCardException!";
                                 } catch (BadUsageException e) {
                                     qDebug() << "VoidAI: BadUsageException!";
                                 } catch (OneBangPerTurnException e) {
                                     qDebug() << "VoidAI: One bang per turn!";
                                 } catch(GameException& e) {
                                     qDebug() << "VoidAI: GameException";
                                 }
                             }
                             break;
                         }
                             break;
                        case CARD_TELEPORT:{
                            QList<PublicPlayerView*> players = mp_playerCtrl->publicGameView().publicPlayerList();
                            foreach (PublicPlayerView* player, players){
                                if (player->id() == mp_playerCtrl->privatePlayerView().id()){
                                     mp_playerCtrl->playCard(card, player);
                                     break;
                                     }
                                }
                            }
                            break;
                         default:
                             break;
                     }
                 } catch (GameException& e) {
                     qDebug() << "VoidAI: (checkpoint #2)";
                     e.debug();
                 }
             }
            // Finish turn or discard random card
            try {
                mp_playerCtrl->finishTurn();
                return;
            } catch (TooManyCardsInHandException e) {
                qDebug() << QString("VoidAI (%1): discarding card").arg(m_id);
                PlayingCard* card = mp_playerCtrl->privatePlayerView().hand().first();
                mp_playerCtrl->discardCard(card);
                return;
            }
            break;
            qDebug() << QString("VoidAI (%1): REQUEST_PLAY 2").arg(m_id);
        }
        case REQUEST_RESPOND: {
           qDebug() << QString("VoidAI (%1): REQUEST_RESPOND").arg(m_id);
            Player* sheriff = mp_playerCtrl->theSheriff();
            GameCycle* gamecycle = &(sheriff->game()->gameCycle());
            ReactionHandler* reactionHandler = gamecycle->reactionHandler();
            if (reactionHandler == 0){
                qDebug() << "reactionHandler is NULL";
                return;
            }
            if (reactionHandler->reactionType() == REACTION_HEALING_BANG){
                qDebug() << "reactionHandler is REACTION_HEALING_BANG";
                try {
                    mp_playerCtrl->pass();
                    return;
                   } catch (BadPlayerException e) {
                    qDebug() << QString("VoidAI (%1): Respond: BadPlayerException").arg(m_id);
                   } catch (GameException& e) {
                    qDebug("Pass exception:");
                    e.debug();
                    }
                return;
            }
            if (mp_playerCtrl->publicGameView().selection().size() > 0) {
                QList<PlayingCard*> cards = mp_playerCtrl->publicGameView().selection();
                int index = rand() % cards.size();
                try {
                    mp_playerCtrl->playCard(cards[index]);
                    return;
                } catch(GameException& e) {
                    qDebug() << QString("VoidAI (%1): Respond - selection: GameException").arg(m_id);
                    e.debug();
                }
            }
            qDebug() << QString("VoidAI (%1): REQUEST_RESPOND").arg(m_id);
            QList<PlayingCard*> table = mp_playerCtrl->privatePlayerView().table();
            foreach (PlayingCard* card, table) {
              if ((card->color() == COLOR_GREEN) && card->isAct() || (card->color() == COLOR_BLUE)){
                  qDebug() << "Trying to play: " << playingCardTypeToString(card->type());
                  try {
                    switch(card->type()) {
                      case CARD_BARREL:
                      {
                        mp_playerCtrl->playCard(card);
                        return;
                        break;
                      }
                      default:
                      break;
                   }
                }
                catch (GameException& e)  {
                    qDebug() << "VoidAI: (checkpoint #0)";
                    e.debug();
                }
              }
            }
            
            QList<PlayingCard*> cards = mp_playerCtrl->privatePlayerView().hand();
            foreach (PlayingCard* c, cards) {
                try {
                    qDebug() << "Trying to play: " << playingCardTypeToString(c->type());
                    mp_playerCtrl->playCard(c);
                    return;
                } catch (BadCardException e) {
                    qDebug() << QString("VoidAI (%1): Respond: BadCardException").arg(m_id);
                } catch (BadPlayerException e) {
                    qDebug() << QString("VoidAI (%1): Respond: BadPlayerException").arg(m_id);
                } catch (GameException& e) {
                    qDebug("VoidAI");
                    e.debug();
                }
            }
            qDebug() << QString("VoidAI (%1): Trying to pass").arg(m_id);
            try {
                mp_playerCtrl->pass();
            } catch (GameException& e) {
                qDebug("Pass exception:");
                e.debug();
            }
            qDebug() << QString("VoidAI (%1): REQUEST_RESPOND 2").arg(m_id);

            return;
        }
        case REQUEST_DISCARD:
            qDebug() << QString("VoidAI (%1): REQUEST_DISCARD").arg(m_id);
            try {
                qDebug() << QString("VoidAI (%1): discarding card").arg(m_id);
                PlayingCard* card = mp_playerCtrl->privatePlayerView().hand().first();
                qDebug() << QString("VoidAI (%1): cards in hand: %2").arg(m_id).arg(
                        mp_playerCtrl->privatePlayerView().hand().size());
                mp_playerCtrl->discardCard(card);
            } catch (BadGameStateException e) {
                qDebug() << QString("VoidAI (%1): BadGameStateException").arg(m_id);
            }
            break;
            qDebug() << QString("VoidAI (%1): REQUEST_DISCARD 2").arg(m_id);
    }
}