#include "voidai2level.h"
#include "playerctrl.h"
#include "publicgameview.h"
#include "privateplayerview.h"
#include "cards.h"
#include "util.h"
#include "characterjourdonnais.h"
#include "charactersidketchum.h"
#include "characterjessejones.h"
#include "characterpropertychange.h"
#include "cardvalleyofshadowsmultishoot.h"

#include <QDebug>
#include <QTimer>
#include <QApplication>
#include <cstdlib> 

VoidAI2Level::VoidAI2Level(QObject* parent):
        VoidAI(parent),
        m_minSheriffHealthForMassAttack(2)
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
                bool jesseJonesSuccess = false;
                if (mp_playerCtrl->character() == CHARACTER_JESSE_JONES){
                    try {
                        
                        Player* player = mp_playerCtrl->mp_player;
                        CharacterJesseJones* jesseJones =  qobject_cast<CharacterJesseJones*>(player->character());
                        PublicPlayerView* targetPublicPlayerView;
                        if ((mp_playerCtrl->role() == ROLE_SHERIFF) && !inEndGame()){
                            targetPublicPlayerView = chooseRandomPLayer();
                        }
                        else {
                            try {
                                 targetPublicPlayerView = chooseTarget();
                            }
                            catch (BadTargetPlayerException ex){
                                 qDebug() << "VoidAI: BadTargetPlayerException!";
                                 mp_playerCtrl->draw();
                            }
                        }
                        try {//Against segfault
                            if (targetPublicPlayerView){
                                //What will be happen if Jesse Jones isn't successfull, because target has no hand cards?
                               Player* targetPlayer = targetPublicPlayerView->player();
                               if (targetPlayer->handSize() > 0){
                                   jesseJones->useAbility(targetPlayer);
                                   jesseJonesSuccess = true;
                               }
                            } 
                            else {
                                mp_playerCtrl->draw();
                            }
                        }
                        catch (BadTargetPlayerException ex){
                             qDebug() << "VoidAI: BadTargetPlayerException!";
                             mp_playerCtrl->draw();
                        }
                    }
                    catch (BadTargetPlayerException ex){
                        qDebug() << "VoidAI: BadTargetPlayerException!";
                        mp_playerCtrl->draw();
                    }
                }
                if (!jesseJonesSuccess) {
                  mp_playerCtrl->draw();
                }
                
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
            QList<PlayingCard*> table = mp_playerCtrl->privatePlayerView().table();
            // Try to use blue cards:
            foreach (PlayingCard* card, hand) {
                try {
                    switch(card->type()) {
                        case CARD_APPALOSSA:
                        case CARD_MUSTANG:
                        case CARD_HIDEOUT:
                        case CARD_SILVER:
                        case CARD_VOLCANIC:
                        case CARD_SCHOFIELD:
                        case CARD_REMINGTON:
                        case CARD_CARABINE:
                        case CARD_WINCHESTER:
                        case CARD_DILIGENZA:
                        case CARD_WELLSFARGO:
                        case CARD_GENERALSTORE:
                        case CARD_DYNAMITE:
                        case CARD_BARREL:
                        case CARD_CANTEEN:
                        case CARD_PEPPERBOX:
                        case CARD_KNIFE:
                        case CARD_DERRINGER:
                        case CARD_BUFFALO_RIFFLE:
                        case CARD_IRON_PLATE:
                        case CARD_SOMBRERO:
                        case CARD_TEN_GALLON_HAT:
                        case CARD_BIBLE:
                        case CARD_HOWITZER:
                        case CARD_CAN_CAN:
                        case CARD_PONY_EXPRESS:
                        case CARD_CONESTOGA:{
                            mp_playerCtrl->playCard(card);
                            return;
                        }
                        case CARD_INDIANS:
                        case CARD_GATLING:{ 
                            try {
                                if (decideAboutMassAttack()){
                                    mp_playerCtrl->playCard(card);
                                    return;
                                }
                                else {
                                    continue;
                                }
                           }
                           catch (BadPlayerException e) {
                              qDebug() << "VoidAI: BadPlayerException!";
                              return;
                          } 
                        } 
                        return;
                        case CARD_BEER:
                        case CARD_LAST_CALL:{ 
                            if (amIWounded()) {
                                try {
                                    mp_playerCtrl->playCard(card);
                                    continue;
                                }
                                catch (BadUsageException ex){
                                    qDebug() << "VoidAI: CARD_BEER BadUsageException!";
                                    continue;
                                }
                                }
                            }
                            case CARD_WHISKEY:{
                            if (amIWounded()) {
                                try {
                                     mp_playerCtrl->playCard(card, mp_playerCtrl->getRandomCardFromHand());
                                     continue;
                                }
                                catch (BadUsageException ex){
                                    qDebug() << "VoidAI: CARD_WHISKEY BadUsageException!";
                                    continue;
                                }
                                }
                        }
                        case CARD_TEQUILA:{
                            if (mp_playerCtrl->role() == ROLE_DEPUTY){
                                if (isTheSheriffWounded()) {
                                try {
                                    mp_playerCtrl->playCard(card, mp_playerCtrl->getRandomCardFromHand(), &(sheriff->playerCtrl()->publicPlayerView()));
                                    continue;
                                    }
                                catch (BadUsageException ex){
                                    qDebug() << "VoidAI: CARD_TEQUILA BadUsageException!";
                                    ex.debug();
                                    continue;
                                }
                              }
                            }
                            if (amIWounded()) {
                                try {
                                    mp_playerCtrl->playCard(card, mp_playerCtrl->getRandomCardFromHand(), &(mp_playerCtrl->publicPlayerView()));
                                    continue;
                                }
                                catch (BadUsageException ex){
                                    qDebug() << "VoidAI: CARD_TEQUILA on myself BadUsageException!";
                                    ex.debug();
                                    continue;
                                }
                                }
                            } 
                        default:
                            break;
                    }
                } catch (GameException& e)  {
                    qDebug() << "VoidAI: (checkpoint #1)";
                    e.debug();
                } 
            }
            foreach (PlayingCard* card, table) { 
              if ((card->color() == COLOR_GREEN) && card->isAct()){
                  try {
                    switch(card->type()) {
                      case CARD_CANTEEN:{ 
                        if (amIWounded()) {
                            mp_playerCtrl->playCard(card);
                            return;
                        }
                      }
                      break;
                      
                      case CARD_PONY_EXPRESS:
                      {
                        mp_playerCtrl->playCard(card);
                        return;
                        break;
                      }
                      case CARD_HOWITZER:
                          {
                            try {
                                if (decideAboutMassAttack()){
                                    mp_playerCtrl->playCard(card);
                                    return;
                                }
                                else {
                                    continue;
                                }
                        } catch (BadPlayerException e) {
                            qDebug() << "VoidAI: BadPlayerException!";
                            return;
                        } 
                        } 
                        return;
                      case CARD_CAN_CAN:
                      case CARD_CONESTOGA:
                      case CARD_PEPPERBOX:
                      case CARD_KNIFE:
                      case CARD_DERRINGER:
                      case CARD_BUFFALO_RIFFLE:
                      {
                             qDebug() << "Choosing target player";
                             if (!(decideAboutShooting())){
                                  continue;
                            }
                             PublicPlayerView* p = chooseTarget();
                            try { 
                                if (decideAboutShooting()){
                                    if (!controllTarget(p)){
                                        continue;
                                    }
                                    mp_playerCtrl->playCard(card, p);
                                    return;
                                    }
                                 } catch (BadTargetPlayerException e) {
                                     qDebug() << "VoidAI: BadTargetPlayerException!";
                                 } catch (BadPlayerException e) {
                                     qDebug() << "VoidAI: BadPlayerException!";
                                 } 
                                 catch (OneBangPerTurnException e) {
                                     qDebug() << "VoidAI: One bang per turn!";
                                 } catch(GameException& e) {
                                     qDebug() << "VoidAI: GameException";
                                 }
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
             foreach (PlayingCard* card, hand) {
                 try {
                     switch(card->type()) {
                         case CARD_BANG:
                         case CARD_DUEL:
                         case CARD_JAIL: 
                         case CARD_PANIC:
                         case CARD_CATBALOU:
                         {
                             qDebug() << "Choosing target player";
                             if (!(decideAboutShooting())){
                                  continue;
                            }
                             PublicPlayerView* p = chooseTarget();
                            try { 
                                if (decideAboutShooting()){
                                    if (!controllTarget(p)){
                                        continue;
                                    }
                                    mp_playerCtrl->playCard(card, p);
                                    return;
                                    }
                                 } catch (BadTargetPlayerException e) {
                                     qDebug() << "VoidAI: BadTargetPlayerException!";
                                 } catch (BadPlayerException e) {
                                     qDebug() << "VoidAI: BadPlayerException!";
                                 } 
                                 catch (OneBangPerTurnException e) {
                                     qDebug() << "VoidAI: One bang per turn!";
                                 } catch(GameException& e) {
                                     qDebug() << "VoidAI: GameException";
                                 }
                             break;
                         }
                         case CARD_SPRINGFIELD:
                         case CARD_RAG_TIME:
                             {
                             qDebug() << "Choosing target player";
                             if (!(decideAboutShooting())){
                                  continue;
                            }
                             PublicPlayerView* p = chooseTarget();
                            try { 
                                if (decideAboutShooting()){
                                    if (!controllTarget(p)){
                                        continue;
                                    }
                                mp_playerCtrl->playCard(card, mp_playerCtrl->getRandomCardFromHand(), p);
                                     return;
                                }
                            } catch (BadTargetPlayerException e) {
                                qDebug() << "VoidAI: BadTargetPlayerException!";
                            } catch (BadPlayerException e) {
                                qDebug() << "VoidAI: BadPlayerException!";
                            } catch (OneBangPerTurnException e) {
                                qDebug() << "VoidAI: One bang per turn!";
                            } catch(GameException& e) {
                                qDebug() << "VoidAI: GameException";
                            }                                 
                             break;
                         }
                             break;
                         case CARD_GHOST: {
                             try {
                             QList<PublicPlayerView*> players = mp_playerCtrl->publicGameView().publicPlayerList();
                             shuffleList(players);
                             
                             if ((mp_playerCtrl->role() == ROLE_SHERIFF) ||
                                 (mp_playerCtrl->role() == ROLE_DEPUTY)){
                                 foreach(const PublicPlayerView* p, players)    {
                                      if ((p->role() == ROLE_DEPUTY) && (!(p->isAlive()))){
                                          mp_playerCtrl->playCard(card, p);
                                          break;
                                      }
                                  }
                             }
                             if (mp_playerCtrl->role() == ROLE_RENEGADE)
                             {}
                             else foreach(const PublicPlayerView* p, players)    {
                                if ((p->role() == ROLE_OUTLAW) && (!(p->isAlive()))){
                                    mp_playerCtrl->playCard(card, p);
                                    break;
                                }
                             }
                             }
                             catch (BadTargetPlayerException e) {
                                qDebug() << "VoidAI: BadTargetPlayerException!";
                            } 
                            catch (BadUsageException e) {
                                qDebug() << "VoidAI: BadUsageException!";
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
             if (mp_playerCtrl->character() == CHARACTER_SID_KETCHUM){
                    try {
                        GameCycle* gamecycle = &(sheriff->game()->gameCycle());
                        qDebug() << gamePlayStateToString(gamecycle->gamePlayState());
                        Player* player = mp_playerCtrl->mp_player;
                        CharacterSidKetchum* sidketchum =  qobject_cast<CharacterSidKetchum*>(player->character());
                        while (amIWounded() && (mp_playerCtrl->privatePlayerView().hand().size() >
mp_playerCtrl->privatePlayerView().lifePoints())){
                             QList<PlayingCard*> healCards = QList<PlayingCard*>();
                             PlayingCard* card1 = player->getRandomCardFromHand();
                             PlayingCard* card2 = player->getRandomCardFromHand();
                             if (card1 == card2) throw BadCardException();
                             healCards.append(card1);
                             healCards.append(card2);
                             sidketchum->useAbility(healCards);
                        }
                    } 
                    catch (BadCardException e) {
                        qDebug() << QString("VoidAI (%1): Respond:     BadCardException").arg(m_id);
                    }
                    catch (BadPlayerException e) {
                        qDebug() << QString("VoidAI (%1): Respond: BadPlayerException").arg(m_id);
                    } catch (GameException& e) {
                        qDebug("VoidAI");
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

            if (mp_playerCtrl->publicGameView().selection().size() > 0) {
                QList<PlayingCard*> cards = mp_playerCtrl->publicGameView().selection();
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
          
            GameCycle* gamecycle = &(sheriff->game()->gameCycle());
            ReactionHandler* reactionHandler = gamecycle->reactionHandler();
            int misseds = calculateMisseds();
            bool defense = true;
            if (reactionHandler == 0){ 
                qDebug() << "VoidAi: reactionHandler is NULL";
            }
            else if (reactionHandler->reactionType() == REACTION_BANG){
                qDebug() << "VoidAi: reactionHandler is REACTION_BANG";
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
            
            qDebug() << QString("VoidAI (%1): REQUEST_RESPOND").arg(m_id);
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
                    } catch (BadPlayerException e) {
                        qDebug() << QString("VoidAI (%1): Respond: BadPlayerException").arg(m_id);
                        return;
                    } catch (BadUsageException e) {
                        qDebug() << QString("VoidAI (%1): Respond: BadUsageException").arg(m_id);
                        return;
                    }
                    catch (GameException& e) {
                        qDebug("VoidAI");
                        e.debug();
                        return;
                    }
                
            }
            qDebug() << "VoidAi: reactionHandler is " << reactionTypeToString(reactionHandler->reactionType()); 
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

//This was in the try block of CARD_HOWITZER
bool VoidAI2Level::decideAboutMassAttack(){
QList<PublicPlayerView*> players = mp_playerCtrl->publicGameView().publicPlayerList();
                             
    if ((mp_playerCtrl->role() == ROLE_SHERIFF) && !inEndGame()){
        qDebug() << "ROLE_SHERIFF";
        return !isDeputyLiving();
    }
    if (mp_playerCtrl->role() == ROLE_DEPUTY){
        return sheriffOnManyLifePoints(m_minSheriffHealthForMassAttack);
    }
    if (mp_playerCtrl->role() == ROLE_RENEGADE)
    {
        if (!inEndGame()){
            return sheriffOnManyLifePoints(m_minSheriffHealthForMassAttack);
        }
    }
    return true;
}

bool VoidAI2Level::decideAboutShooting(){
    if (mp_playerCtrl->role() != ROLE_SHERIFF) return true;
    if (inEndGame()) return true;
    return !isDeputyLiving();
}

PublicPlayerView* VoidAI2Level::chooseTarget(){
    Player* sheriff = mp_playerCtrl->theSheriff();
    QList<PublicPlayerView*> players = mp_playerCtrl->publicGameView().publicPlayerList();
    shuffleList(players);
    if ((mp_playerCtrl->role() == ROLE_SHERIFF) && !inEndGame()){
        qDebug() << "ROLE_SHERIFF";
        if (isDeputyLiving()){
            throw BadTargetPlayerException();
            }
        }
        PublicPlayerView* p = 0;
        foreach(p, players) {
            if (mp_playerCtrl->privatePlayerView().id() == p->id()) {
                continue;
            }
            if (mp_playerCtrl->role() == ROLE_DEPUTY){
                qDebug() << "ROLE_DEPUTY";
                if (p != 0 && !(sheriff->publicView().id() == p->id()) && !(mp_playerCtrl->privatePlayerView().id() == p->id())  ){
                    break; 
                }
            }
            if (mp_playerCtrl->role() == ROLE_RENEGADE){
                qDebug() << "ROLE_RENEGADE";
                if (p != 0 && !(sheriff->publicView().id() == p->id()) && !(mp_playerCtrl->privatePlayerView().id() == p->id()) && !inEndGame()){
                    break; 
                }
            }
        }
        if (mp_playerCtrl->role() == ROLE_OUTLAW){
            qDebug() << "ROLE_OUTLAW";
            p = &sheriff->publicView();
        }
        return p;
}

bool VoidAI2Level::controllTarget(PublicPlayerView* p){
    if (p == 0){
        return false;
    }
    if (mp_playerCtrl->privatePlayerView().id() == p->id()) {
        return false;
    }
    if (!p->isAlive()){
        return false;
    }
    return true;
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
            } catch (BadPlayerException e) {
                qDebug() << QString("VoidAI (%1): Respond: BadPlayerException").arg(m_id);
            } catch (GameException& e) {
                qDebug("VoidAI");
                e.debug();
            }
        }
    }
    
}

int VoidAI2Level::calculateMisseds(){
    int misseds = 0;
    QList<PlayingCard*> hand = mp_playerCtrl->privatePlayerView().hand();
    foreach (PlayingCard* c, hand) {
        if (c->type() == CARD_MISSED) misseds++;
        if (c->type() == CARD_DODGE) misseds++;
    }
    QList<PlayingCard*> table = mp_playerCtrl->privatePlayerView().table();
    foreach (PlayingCard* c, table) {
        if (c->type() == CARD_IRON_PLATE) misseds++;
        if (c->type() == CARD_SOMBRERO) misseds++;
        if (c->type() == CARD_TEN_GALLON_HAT) misseds++;
        if (c->type() == CARD_BIBLE) misseds++;
    }
    return misseds;
}

PublicPlayerView* VoidAI2Level::chooseRandomPLayer(){
    QList<PublicPlayerView*> players = mp_playerCtrl->publicGameView().publicPlayerList();
    shuffleList(players);
    PublicPlayerView* targetPublicPlayerView = players.first();
    if (mp_playerCtrl->privatePlayerView().id() ==      targetPublicPlayerView->id()){
        targetPublicPlayerView = players.last();
    }
    return targetPublicPlayerView;
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

bool VoidAI2Level::sheriffOnManyLifePoints(int n){
    //It cann't use m_minSheriffHealthForMassAttack as a member because of segmentation fault in client
    Player* sheriff = mp_playerCtrl->theSheriff();
    return (sheriff->publicView().lifePoints() > n);
}

bool VoidAI2Level::amIWounded(){
  return (mp_playerCtrl->privatePlayerView().lifePoints() < mp_playerCtrl->privatePlayerView().maxLifePoints());
}

bool VoidAI2Level::isTheSheriffWounded(){
  Player* sheriff = mp_playerCtrl->theSheriff();
  return (sheriff->playerCtrl()->privatePlayerView().lifePoints() <
    sheriff->playerCtrl()->privatePlayerView().maxLifePoints());
}
