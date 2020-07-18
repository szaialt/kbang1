#include "voidai2level.h"
#include "playerctrl.h"
#include "publicgameview.h"
#include "privateplayerview.h"
#include "cards.h"
#include "util.h"
#include "characterjourdonnais.h"
#include "gametable.h"

#include <QDebug>
#include <QTimer>
#include <QApplication>
#include <cstdlib>

VoidAI2Level::VoidAI2Level(QObject* parent):
        VoidAI(parent)
{
    //moveToThread(QApplication::instance()->thread());
}

void VoidAI2Level::requestWithAction()
{
    qDebug() << QString("VoidAI (%1): onActionRequest(%2)").arg(m_id).arg(m_requestType);
    if (mp_playerCtrl->publicGameView().gameContextData().requestedPlayerId != mp_playerCtrl->privatePlayerView().id()) {
        QString("VoidAI (%1): Not requested!").arg(m_id);
        return;
    }
    Player* sheriff = mp_playerCtrl->theSheriff();
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
            foreach (PlayingCard* card, table) {/*
              if ((card->color() == COLOR_GREEN) && card->isAct()){
                  try {
                    switch(card->type()) {
                      case CARD_GREEN_FUR_TRADE:
                      case CARD_WAR_PARTY:
                      case CARD_PLUNDER:
                      case CARD_BAR_FIGHT:
                      case CARD_PILFER:
                      case CARD_GREEN_ON_THE_HOUSE:
                      case CARD_HATCHET:
                      case CARD_RICOCHET:
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
              }*/
            }
            // Try to use blue cards:
            foreach (PlayingCard* card, hand) {
                try {
                    switch(card->type()) {
                        case CARD_APPALOSSA:
                        case CARD_MUSTANG:
                        case CARD_VOLCANIC:
                        case CARD_BULLDOG_1:
                        case CARD_WALKER:
                        case CARD_SCHOFIELD:
                        case CARD_REMINGTON:
                        case CARD_CARABINE:
                        case CARD_WINCHESTER:
                        case CARD_DILIGENZA:
                        case CARD_WELLSFARGO:
                        case CARD_GENERALSTORE:
                        case CARD_DYNAMITE:
                        case CARD_BARREL:
                        case CARD_HALF_ZATOCHI:
                        case CARD_MEDI_GUN:
                        case CARD_SANDMAN:
                        case CARD_PERSUASION:
                        case CARD_ACE_UP_YOUR_SLEEVE:
                        case CARD_UNION_PACIFIC:
                        case CARD_HIDDEN_WEAPON:
                        case CARD_MEMENTO:
                        case CARD_PACKING_MULE:
                        case CARD_PEACE_PIPE:
                        case CARD_SHOTGUN:
                        case CARD_ADRENALINE:
                        case CARD_MEDICINES:
                        case CARD_STEROID:
                        case CARD_DRUGS:
                        case CARD_MORPHINE:
                        case CARD_VEST:
                        case CARD_STUNNING:
                        case CARD_COWBOY_POCKET:
                        case CARD_GOLD_WATCH:
                        case CARD_PRAYER:
                        case CARD_HILL_TOP:
                        case CARD_PACK_MULE:
                        case CARD_GAMBLE:
                        case CARD_ROB_GRAVE:
                        case CARD_GREEN_FUR_TRADE:
                        case CARD_WAR_PARTY:
                        case CARD_PLUNDER:
                        case CARD_BAR_FIGHT:
                        case CARD_PILFER:
                        case CARD_GREEN_ON_THE_HOUSE:
                        case CARD_HATCHET:
                        case CARD_RICOCHET:
                        {
                            mp_playerCtrl->playCard(card);
                            continue;
                        }
                        case CARD_INDIANS:
                        case CARD_GATLING:
                        case CARD_MANN_VS_MACHINE:
                        case CARD_KILLER:
                        case CARD_BROWN_SHOW_TIME:
                        //case CARD_BANDIDOS:
                        {
                            try {
                             QList<PublicPlayerView*> players = mp_playerCtrl->publicGameView().publicPlayerList();
                             
                            if ((mp_playerCtrl->role() == ROLE_SHERIFF) && !inEndGame()){
                                 qDebug() << "ROLE_SHERIFF";
                                if (isDeputyLiving()){
                                 continue;
                                }
                            }
                            if (mp_playerCtrl->role() == ROLE_DEPUTY){
                                if (sheriffOnMoreThanTwoLifePoints()){
                                    PlayingCard* persuasion = 0;
                                    foreach (persuasion, table){
                                        if (persuasion->type() == CARD_PERSUASION)
                                            break;
                                    }
                                    if (persuasion != 0){
                                        foreach (PlayingCard* card2, hand){
                                            if (card2->type() == CARD_BEER){
                                                persuasion->play(card2, sheriff);
                                                break;
                                            }
                                            if (card->type() == CARD_GATLING){
                                                if (card2->type() == CARD_MISSED){
                                                    persuasion->play( card2, sheriff);
                                                    break;
                                                }
                                            }
                                            else {
                                                if (card2->type() == CARD_BANG){
                                                    persuasion->play( card2, sheriff);
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    mp_playerCtrl->playCard(card);
                                }
                                else {
                                    continue;
                                }
                            }
                            if (mp_playerCtrl->role() == ROLE_RENEGADE)
                            {
                                if (!inEndGame()){
                                  if (sheriffOnMoreThanTwoLifePoints()){
                                    mp_playerCtrl->playCard(card);
                                  }
                                  else {
                                    continue;
                                  }
                                }
                                else {
                                    mp_playerCtrl->playCard(card);
                                }
                            }
                            else {
                              mp_playerCtrl->playCard(card);
                            }
                            continue; 
                        }
                        
                        catch (BadPlayerException e) {
                            qDebug() << "VoidAI: BadPlayerException!";
                            continue;
                        } 
                        catch (BadCardException e) {
                            qDebug() << "VoidAI: BadCardException!";
                        } 
                        catch (BadUsageException e) {
                            qDebug() << "VoidAI: BadUsageException!";
                            continue;
                        }
                        } 
                        continue;
                        case CARD_BEER:
                        case CARD_MAD_MILK:
                        case CARD_SANDVICH: 
                        case CARD_FIRST_AID_KIT:
                        { 
                            if (amIWounded()) {
                                mp_playerCtrl->playCard(card);
                                continue;
                                }
                        }
                        default:
                            break;
                    }
                } catch (BadCardException e) {
                    qDebug() << "VoidAI: BadCardException!";
                } catch (BadUsageException e) {
                    qDebug() << "VoidAI: BadUsageException!";
                }  catch (GameException& e)  {
                    qDebug() << "VoidAI: (checkpoint #1)";
                    e.debug();
                }
            }
            foreach (PlayingCard* card, table) { 
              if (/*(card->color() == COLOR_GREEN) && */card->isAct()){
                  try {
                    switch(card->type()) {
                      case CARD_MEDICINES:{ 
                        if (mp_playerCtrl->privatePlayerView().lifePoints() <
                           mp_playerCtrl->privatePlayerView().maxLifePoints()) {
                            mp_playerCtrl->playCard(card);
                            continue;
                        }
                      }
                      break;
                      case CARD_ADRENALINE:
                      case CARD_GOLD_WATCH:
                      {
                        mp_playerCtrl->playCard(card);
                        break;
                      }
                      case CARD_WAR_PARTY:
                      case CARD_ROULETTE:
                      {
                        try {
                             QList<PublicPlayerView*> players = mp_playerCtrl->publicGameView().publicPlayerList();
                             
                            if ((mp_playerCtrl->role() == ROLE_SHERIFF) && !inEndGame()){
                                 qDebug() << "ROLE_SHERIFF";
                                if (isDeputyLiving()){
                                 continue;
                                }
                            }
                            if (mp_playerCtrl->role() == ROLE_DEPUTY){
                                if (sheriffOnMoreThanTwoLifePoints()){
                                    PlayingCard* persuasion = 0;
                                    foreach (persuasion, table){
                                        if (persuasion->type() == CARD_PERSUASION)
                                            break;
                                    }
                                    if (persuasion != 0){
                                        foreach (PlayingCard* card2, hand){
                                            if (card2->type() == CARD_BEER){
                                                persuasion->play(card2, sheriff);
                                                break;
                                            }
                                            if (card->type() == CARD_GATLING){
                                                if (card2->type() == CARD_MISSED){
                                                    persuasion->play( card2, sheriff);
                                                    break;
                                                }
                                            }
                                            else {
                                                if (card2->type() == CARD_BANG){
                                                    persuasion->play( card2, sheriff);
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    mp_playerCtrl->playCard(card);
                                }
                                else {
                                    continue;
                                }
                            }
                            if (mp_playerCtrl->role() == ROLE_RENEGADE)
                            {
                                if (!inEndGame()){
                                  if (sheriffOnMoreThanTwoLifePoints()){
                                    mp_playerCtrl->playCard(card);
                                  }
                                  else {
                                    continue;
                                  }
                                }
                                else {
                                    mp_playerCtrl->playCard(card);
                                }
                            }
                            else {
                              mp_playerCtrl->playCard(card);
                            }
                            continue; 
                        }
                        
                        catch (BadPlayerException e) {
                            qDebug() << "VoidAI: BadPlayerException!";
                            continue;
                        } 
                        catch (BadCardException e) {
                            qDebug() << "VoidAI: BadCardException!";
                        } 
                        catch (BadUsageException e) {
                            qDebug() << "VoidAI: BadUsageException!";
                            continue;
                        }
                        break;
                      }
                     case CARD_PLUNDER:
                          {
                        QList<PublicPlayerView*> players = mp_playerCtrl->publicGameView().publicPlayerList();
                        shuffleList(players);
                        foreach(const PublicPlayerView* p, players) {
                          if (mp_playerCtrl->privatePlayerView().id() == p->id()) {
                              continue;
                          }
                          QList<PlayingCard*> table3 = p->table();
                          shuffleList(table3);
                          try {
                              foreach (PlayingCard* card3, p->table()) {
                                 QList<PlayingCard*> cards;
                                 cards.append(mp_playerCtrl->getRandomCardFromHand());
                                 cards.append(card3);
                                 mp_playerCtrl->playCard(card, cards);
                                 continue;
                              }
                          } catch (BadTargetPlayerException e) {
                          qDebug() << "VoidAI: BadTargetPlayerException!";
                          } catch (OneBangPerTurnException e) {
                            qDebug() << "VoidAI: One bang per turn!";
                          } catch(GameException& e) {
                            qDebug() << "VoidAI: GameException";
                          }
                        }
                      }
                      break;
                      case CARD_PILFER:
                      case CARD_GREEN_FUR_TRADE: {
                        QList<PublicPlayerView*> players = mp_playerCtrl->publicGameView().publicPlayerList();
                        shuffleList(players);
                        foreach(const PublicPlayerView* p, players) {
                          if (mp_playerCtrl->privatePlayerView().id() == p->id()) {
                              continue;
                          }
                          QList<PlayingCard*> table2 = p->table();
                          shuffleList(table2);
                          try {
                              foreach (PlayingCard* card2, table2) {
                                 mp_playerCtrl->playCard(card, card2);
                                 continue;
                              }
                          } catch (BadTargetPlayerException e) {
                          qDebug() << "VoidAI: BadTargetPlayerException!";
                          } catch (OneBangPerTurnException e) {
                            qDebug() << "VoidAI: One bang per turn!";
                          } catch(GameException& e) {
                            qDebug() << "VoidAI: GameException";
                          }
                        }
                      }
                      break;
                      case CARD_GREEN_ON_THE_HOUSE:
                          {
                            if (mp_playerCtrl->privatePlayerView().lifePoints() <
                                    mp_playerCtrl->privatePlayerView().maxLifePoints()) {
                                mp_playerCtrl->playCard(card, mp_playerCtrl->getRandomCardFromHand());
                                continue;
                                }
                        }
                          break;
                      case CARD_HATCHET:
                      case CARD_BAR_FIGHT:
                          {
                             qDebug() << "Choosing target player";
                             QList<PublicPlayerView*> players = mp_playerCtrl->publicGameView().publicPlayerList();
                             shuffleList(players);
                             bool shoot = true;
                             if ((mp_playerCtrl->role() == ROLE_SHERIFF) && !inEndGame()){
                                 qDebug() << "ROLE_SHERIFF";
                                if (isDeputyLiving()){
                                 shoot = false;
                                 continue;
                                }
                            }
                             PublicPlayerView* p = 0;
                             foreach(p, players) {
                                 if (mp_playerCtrl->privatePlayerView().id() == p->id()) {
                                     continue;
                                 }
                                if (mp_playerCtrl->role() == ROLE_DEPUTY){
                                    qDebug() << "ROLE_DEPUTY";
                                    if (p != 0 && !(sheriff->publicView().id() == p->id()) && !(mp_playerCtrl->privatePlayerView().id() == p->id()) ){
                                        break; 
                                    }
                                }
                                if (mp_playerCtrl->role() == ROLE_RENEGADE){
                                    qDebug() << "ROLE_RENEGADE";
                                    if (p != 0 && !(sheriff->publicView().id() == p->id()) && !(mp_playerCtrl->privatePlayerView().id() == p->id())  && !inEndGame()){
                                        break; 
                                    }
                                }
                             }
                             if (mp_playerCtrl->role() == ROLE_OUTLAW){
                                 qDebug() << "ROLE_OUTLAW";
                                 p = &sheriff->publicView();
                            }
                            try { 
                                     if (!((mp_playerCtrl->role() == ROLE_SHERIFF) && (!shoot))){
                                         if (p == 0){
                                            continue;
                                         }
                                         if (mp_playerCtrl->privatePlayerView().id() == p->id()) {
                                            continue;
                                         }
                                         if (!p->isAlive()){
                                           continue;
                                         }
                                       mp_playerCtrl->playCard(card, p);
                                     return;
                                     }
                                 } catch (BadTargetPlayerException e) {
                                     qDebug() << "VoidAI: BadTargetPlayerException!";
                                 } catch (BadPlayerException e) {
                                     qDebug() << "VoidAI: BadPlayerException!";
                                 } catch (BadCardException e) {
                                     qDebug() << "VoidAI: BadCardException!";
                                 } catch (BadUsageException e) {
                                     qDebug() << "VoidAI: BadUsageException!";
                                 }   catch (OneBangPerTurnException e) {
                                     qDebug() << "VoidAI: One bang per turn!";
                                 } catch(GameException& e) {
                                     qDebug() << "VoidAI: GameException";
                                 }
                                 continue;
                             break;
                         }
                      default:
                          continue;
                      break;
                } 
              } 
              catch (GameException& e)  {
                    qDebug() << "VoidAI: (checkpoint #0)";
                    e.debug();
                }
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
                         case CARD_SUN_GLARE:
                         case CARD_HEADACHE:
                         case CARD_SHOCK:
                         case CARD_WEAKNESS:
                         case CARD_INFLAMMATORY_BOTTLE:
                         case CARD_BLEEDING_INJURY:
                         case CARD_DIRTY_JOB:
                         case CARD_THUNDER:
                         case CARD_SHOWNDOWN:
                         case CARD_BROWN_MOLOTOV_COCKTAIL:
                                
                         {
                             qDebug() << "Choosing target player";
                             QList<PublicPlayerView*> players = mp_playerCtrl->publicGameView().publicPlayerList();
                             shuffleList(players);
                             bool shoot = true;
                             if ((mp_playerCtrl->role() == ROLE_SHERIFF) && !inEndGame()){
                                 qDebug() << "ROLE_SHERIFF";
                                if (isDeputyLiving()){
                                 shoot = false;
                                 continue;
                                }
                            }
                             PublicPlayerView* p = 0;
                             foreach(p, players) {
                                 if (mp_playerCtrl->privatePlayerView().id() == p->id()) {
                                     continue;
                                 }
                                if (mp_playerCtrl->role() == ROLE_DEPUTY){
                                    qDebug() << "ROLE_DEPUTY";
                                    if (p != 0 && !(sheriff->publicView().id() == p->id()) && !(mp_playerCtrl->privatePlayerView().id() == p->id()) ){
                                        break; 
                                    }
                                }
                                if (mp_playerCtrl->role() == ROLE_RENEGADE){
                                    qDebug() << "ROLE_RENEGADE";
                                    if (p != 0 && !(sheriff->publicView().id() == p->id()) && !(mp_playerCtrl->privatePlayerView().id() == p->id())  && !inEndGame()){
                                        break; 
                                    }
                                }
                             }
                             if (mp_playerCtrl->role() == ROLE_OUTLAW){
                                 qDebug() << "ROLE_OUTLAW";
                                 p = &sheriff->publicView();
                            }
                            try { 
                                     if (!((mp_playerCtrl->role() == ROLE_SHERIFF) && (!shoot))){
                                         if (p == 0){
                                            continue;
                                         }
                                         if (mp_playerCtrl->privatePlayerView().id() == p->id()) {
                                            continue;
                                         }
                                         if (!p->isAlive()){
                                           continue;
                                         }
                                       mp_playerCtrl->playCard(card, p);
                                     return;
                                     }
                                 } catch (BadTargetPlayerException e) {
                                     qDebug() << "VoidAI: BadTargetPlayerException!";
                                 } catch (BadPlayerException e) {
                                     qDebug() << "VoidAI: BadPlayerException!";
                                 } catch (BadCardException e) {
                                     qDebug() << "VoidAI: BadCardException!";
                                 } catch (BadUsageException e) {
                                     qDebug() << "VoidAI: BadUsageException!";
                                 }   catch (OneBangPerTurnException e) {
                                     qDebug() << "VoidAI: One bang per turn!";
                                 } catch(GameException& e) {
                                     qDebug() << "VoidAI: GameException";
                                 }
                                 continue;
                             break;
                         }
                         case CARD_SUPPLY_CRATE:
                         case CARD_BROWN_INVESTMENT:
                             {
                                 try {
                                     mp_playerCtrl->playCard(card, mp_playerCtrl->getRandomCardFromHand());
                                        continue;
                                }
                            catch (BadTargetPlayerException e) {
                                qDebug() << "VoidAI: BadTargetPlayerException!";
                            } catch (BadPlayerException e) {
                                qDebug() << "VoidAI: BadPlayerException!";
                            } catch (OneBangPerTurnException e) {
                                qDebug() << "VoidAI: One bang per turn!";
                            } catch (BadCardException e) {
                                qDebug() << "VoidAI: BadCardException!";
                            } catch (BadUsageException e) {
                                qDebug() << "VoidAI: BadUsageException!";
                            } catch(GameException& e) {
                                qDebug() << "VoidAI: GameException";
                            }   
                            continue;
                             break;
                         }
                         continue;
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
                GameCycle* gamecycle = &(sheriff->game()->gameCycle());
                if (gamecycle->isResponse())
                    return;
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
            GameCycle* gamecycle = &(sheriff->game()->gameCycle());
            ReactionHandler* reactionHandler = gamecycle->reactionHandler();
            if (reactionHandler == 0){
                qDebug() << "reactionHandler is NULL";
                return;
            }
            else if (reactionHandler->reactionType() == REACTION_HEALING_BANG){
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
            else if (reactionHandler->reactionType() == REACTION_GENERALSTORE)  {
                QList<PlayingCard*> cards = mp_playerCtrl->publicGameView().selection();
                if (cards.size() == 0) {
                    try {
                        mp_playerCtrl->pass();
                        return;
                    } catch (GameException& e) {
                        qDebug("Pass exception:");
                        e.debug();
                        return;
                    }
                }
                else {
                    int index = rand() % cards.size();
                    try {
                        mp_playerCtrl->playCard(cards[index]);
                        return;
                    } catch(GameException& e) {
                        qDebug() << QString("VoidAI (%1): Respond - selection: GameException").arg(m_id);
                        e.debug();
                        return;
                    }
                }
            }
            else if (mp_playerCtrl->publicGameView().selection().size() > 0) {
                QList<PlayingCard*> cards = mp_playerCtrl->publicGameView().selection();
                int index = rand() % cards.size();
                try {
                    mp_playerCtrl->playCard(cards[index]);
                    return;
                } catch(GameException& e) {
                    qDebug() << QString("VoidAI (%1): Respond - selection: GameException").arg(m_id);
                    e.debug();
                    if (reactionHandler->reactionType() ==  REACTION_GENERALSTORE){
                        return;
                    }
                }
                
            }

            qDebug() << QString("VoidAI (%1): REQUEST_RESPOND").arg(m_id);
            
            int misseds = calculateMisseds();
            bool defense = true;
            
            /*else if (reactionHandler->reactionType() == REACTION_BANDIDOS){
                CardValleyOfShadowMultiShoot* bandidos = (CardValleyOfShadowMultiShoot*)(reactionHandler);
                int missedLeft1 = bandidos->missedLeft();
                if (mp_playerCtrl->privatePlayerView().hand().size() < missedLeft1){
                    qDebug() << QString("VoidAI (%1): Trying to pass").arg(m_id);
                    try {
                        mp_playerCtrl->pass();
                        return;
                   } catch (BadPlayerException e) {
                        qDebug() << QString("VoidAI (%1): Respond: BadPlayerException").arg(m_id);
                   } catch (GameException& e) {
                    qDebug("Pass exception:");
                    e.debug();
                    return;
                    }
                } 
                //bandidos->requestNext();
                Player* player = mp_playerCtrl->mp_player;
                if (player->payedBandidos()) return;
            }*/
            if (reactionHandler->reactionType() == REACTION_BANG){
                qDebug() << "REACTION_BANG";
                Player* attacker = reactionHandler->causedBy();
                CharacterBase* character = attacker->character();
                CardBang* bang = (CardBang*)(reactionHandler);
                int left = bang->missedLeft();
                if (character != NULL){
                    CharacterType characterType = attacker->character()->characterType();
                    if (characterType == CHARACTER_SLAB_THE_KILLER){
                        if (left > misseds){
                             defense = false; 
                        }
                    }
                }
                
            }
            if (mp_playerCtrl->character() == CHARACTER_SUZY_LAFAYETTE){
                defense = true;
                QList<PlayingCard*> hand = mp_playerCtrl->privatePlayerView().hand();
                playCardForDefense(hand, defense);
            }
            
            qDebug() << QString("VoidAI (%1): REQUEST_RESPOND 2").arg(m_id);
            if (mp_playerCtrl->character() == CHARACTER_JOURDONNAIS){
                Player* player = mp_playerCtrl->mp_player;
                CharacterJourdonnais* jourdonnais =  qobject_cast<CharacterJourdonnais*>(player->character());
                try {
                    jourdonnais->useAbility();
                    return;
                }
                catch (BadCardException e) {
                    qDebug() << QString("VoidAI (%1): Respond: BadCardException").arg(m_id);
                    return;
                }
                catch (BadPlayerException e) {
                    qDebug() << QString("VoidAI (%1): Respond: BadPlayerException").arg(m_id);
                    return;
                }
                catch (BadUsageException e) {
                    qDebug() << QString("VoidAI (%1): Respond: BadUsageException").arg(m_id);
                    return;
                }
                catch (GameException& e) {
                        qDebug("VoidAI");
                        e.debug(); 
                        return;
                }
 
            }
            QList<PlayingCard*> table = mp_playerCtrl->privatePlayerView().table();
            playCardForDefense(table, defense);
            QList<PlayingCard*> hand = mp_playerCtrl->privatePlayerView().hand();
            playCardForDefense(hand, defense);
            qDebug() << QString("VoidAI (%1): Trying to pass").arg(m_id);
            try {
                mp_playerCtrl->pass();
            } catch (GameException& e) {
                qDebug("Pass exception:");
                e.debug();
                return;
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

bool VoidAI2Level::inEndGame(){
  Player* sheriff = mp_playerCtrl->theSheriff();
  return (sheriff->game()->alivePlayersCount() <= 2);
}

bool VoidAI2Level::isDeputyLiving(){
  int deputyNumber = 1;
  int calculator = 0;
  if (mp_playerCtrl->publicGameView().publicPlayerList().count() == 4)
    deputyNumber = 0;
  if (mp_playerCtrl->publicGameView().publicPlayerList().count() > 6)
    deputyNumber = 2;
  QList<PublicPlayerView*> players = mp_playerCtrl->publicGameView().publicPlayerList();
  foreach(const PublicPlayerView* p, players) {
    if ((p->role() == ROLE_DEPUTY) && (!(p->isAlive()))){
      calculator++;
      }
    }
    qDebug() << "ROLE_DEPUTY: " << calculator;
    qDebug() << "from" << deputyNumber;
    return (calculator < deputyNumber);
}

bool VoidAI2Level::sheriffOnMoreThanTwoLifePoints(){
    Player* sheriff = mp_playerCtrl->theSheriff();
    return (sheriff->publicView().lifePoints() > 2);
}

bool VoidAI2Level::amIWounded(){
  return (mp_playerCtrl->privatePlayerView().lifePoints() < mp_playerCtrl->privatePlayerView().maxLifePoints());
}

bool VoidAI2Level::isTheSheriffWounded(){
  Player* sheriff = mp_playerCtrl->theSheriff();
  return (sheriff->playerCtrl()->privatePlayerView().lifePoints() <
    sheriff->playerCtrl()->privatePlayerView().maxLifePoints());
}

int VoidAI2Level::calculateMisseds(){
    int misseds = 0;
    QList<PlayingCard*> hand = mp_playerCtrl->privatePlayerView().hand();
    foreach (PlayingCard* c, hand) {
        if (c->type() == CARD_MISSED) misseds++;
        if (c->type() == CARD_DEAD_RINGER) misseds++;
    }
    return misseds;
}

void VoidAI2Level::playCardForDefense(QList<PlayingCard*> list, bool defense){
    foreach (PlayingCard* c, list) {
        if (defense){
            try {
                qDebug() << "Trying to play: " << playingCardTypeToString(c->type());
                mp_playerCtrl->playCard(c);
                return;
            } catch (BadCardException e) {
                qDebug() << QString("VoidAI (%1): Respond: BadCardException").arg(m_id);
                continue;
            } catch (BadPlayerException e) {
                qDebug() << QString("VoidAI (%1): Respond: BadPlayerException").arg(m_id);
                continue;
            } catch (GameException& e) {
                qDebug("VoidAI");
                e.debug();
                continue;
            }
        }
    }
    
}

