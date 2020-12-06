/***************************************************************************
 *   Copyright (C) 2008 by MacJariel                                       *
 *   echo "badmailet@gbalt.dob" | tr "edibmlt" "ecrmjil"                   *
 *                                                                        *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <QXmlStreamWriter>
#include <QTimer>

#include "game.h"
#include "gameserver.h"
#include "client.h"
#include "player.h"
#include "common.h"
#include "cardbeer.h"
#include "util.h"
#include "config.h"
#include "gameexceptions.h"


#include "gameinfo.h"
#include "gametable.h"
#include "gamecycle.h"
#include "gameeventmanager.h"
#include "gamelogger.h"
#include "characterbase.h"
#include "characterlist.h"
#include "playerreaper.h"
#include "voidai.h"
#include "voidai2level.h"
#include "voidai3level.h"
#include "charactertomyleeghost.h"

#include <stdexcept>
#include <iostream>

Game::Game(GameServer* parent, int gameId, const CreateGameData& createGameData):
    QObject(parent),
    m_id(gameId),
    m_state(GAMESTATE_WAITINGFORPLAYERS),
    m_publicGameView(this),
    m_nextUnusedPlayerId(0),
    m_startable(0)
{
    mp_gameInfo = new GameInfo(createGameData);
    Q_ASSERT(!(mp_gameInfo == nullptr));
    mp_gameTable = new GameTable(this);
    mp_gameCycle = new GameCycle(this);
    mp_gameEventManager = new GameEventManager(this);
    mp_beerRescue = new BeerRescue(this);
    mp_defaultPlayerReaper = new PlayerReaper(this);
    mp_playerReaper = mp_defaultPlayerReaper;
    mp_gameLogger = new GameLogger();
    mp_gameEventManager->registerSupervisor(mp_gameLogger);
    createAI(mp_gameInfo->AIPlayers());

}

Game::~Game()
{
    // We need to unregister handlers before we delete
    // gameEventManager
    foreach(Player* player, m_playerList)
        player->unregisterGameEventListener();

    delete mp_gameInfo;
    delete mp_gameTable;
    delete mp_gameEventManager;
    delete mp_defaultPlayerReaper;
    delete mp_gameLogger;
}

int Game::alivePlayersCount() const
{
    
    int livingPlayers = 0;
    foreach(const Player* p, playerList())    
    {
        if (p->isAlive()) livingPlayers++;
    }
    return livingPlayers;
    //return m_goodGuysCount + m_outlawsCount + m_renegadesCount;
}

Player* Game::player(int playerId)
{
    if (m_playerMap.contains(playerId))
        return m_playerMap[playerId];
    return 0;
}

Player* Game::nextPlayer(Player* currentPlayer) {
    QListIterator<Player*> it(m_playerList);
    if (!it.findNext(currentPlayer))
        return 0;
    // Now the it points right after the currentPlayer

    // If the currentPlayer is last in list, rewind
    if (!it.hasNext())
        it.toFront();

    while (!it.peekNext()->isAlive()) {
        // @invariant: the player after the iterator is dead
        it.next();
        if (!it.hasNext())
            it.toFront();
    }
    // The player after the iterator is the first alive player
    // after the currentPlayer
    return it.next();
}

Player* Game::previousPlayer(Player* currentPlayer){
    QListIterator<Player*> it(m_playerList);
    qDebug() << currentPlayer->name();
  
    if (!it.findNext(currentPlayer)){
        return 0;
        // Now the it points right after the currentPlayer
    }
    it.previous();
    // Now the it points right before the currentPlayer
    // If the currentPlayer is first in list, rewind
    if (!it.hasPrevious()){
        it.toBack();
    }

    while (!it.peekPrevious()->isAlive()) {
        // @invariant: the player before the iterator is dead
        it.previous();
        if (!it.hasPrevious()){
            it.toBack();
        }
    }

    return it.previous();
}

int Game::getDistance(Player *fromPlayer, Player *toPlayer) const
{
    static int infiniteDistance = 99;
    if (!fromPlayer->isAlive() || !toPlayer->isAlive())
        return infiniteDistance;

    int fromIndex = m_playerList.indexOf(fromPlayer);
    int toIndex   = m_playerList.indexOf(toPlayer);
    if (fromIndex == -1 || toIndex == -1)
        return infiniteDistance;

    // A player is always at distance 1 from himself
    if (fromIndex == toIndex)
        return 1;
    
    int upIndex   = fromIndex;
    int downIndex = fromIndex;
    int baseDistance = 0;
    while (upIndex != toIndex && downIndex != toIndex) {
        do {
            upIndex++;
            if (upIndex == m_playerList.size()) upIndex = 0;
        } while (!m_playerList[upIndex]->isAlive());
        do {
            downIndex--;
            if (downIndex == -1) downIndex = m_playerList.size() - 1;
        } while (!m_playerList[downIndex]->isAlive());
        baseDistance++;
    }
   if (fromPlayer->characterType() == CHARACTER_MYKE_MYOPE){
        if (baseDistance < 2) 
            baseDistance++;
         else return infiniteDistance;
   }
    baseDistance -= fromPlayer->distanceOut();
    baseDistance += toPlayer->distanceIn();
    return baseDistance;
}

Player* Game::createPlayer(const CreatePlayerData& createPlayerData, GameEventListener* handler)
{
    if (m_state != GAMESTATE_WAITINGFORPLAYERS) {
        throw BadGameStateException();
    }
    while ((m_nextUnusedPlayerId == 0) || m_playerMap.contains(m_nextUnusedPlayerId))
    {
        m_nextUnusedPlayerId++;
    }
    Player* newPlayer = new Player(this, m_nextUnusedPlayerId, createPlayerData);
    m_playerMap[m_nextUnusedPlayerId] = newPlayer;
    m_playerList.append(newPlayer);
    m_publicPlayerList.append(&newPlayer->publicView());

    // The first connected nonAI player is the creator and can start the game
    if (mp_gameInfo->creatorId() == 0 && !handler->isAI()) {
        mp_gameInfo->setCreatorId(m_nextUnusedPlayerId);
    }
    newPlayer->registerGameEventListener(handler);
    gameEventManager().onPlayerJoinedGame(newPlayer);
    checkStartable();
    return newPlayer;
}

void Game::createAI(int count)
{
    int level = mp_gameInfo->aiLevel();
    for(int i = 0; i < count; ++i) {
        VoidAI* ai; 
        if (level < 2)
          ai = new VoidAI(this);
        else if (level == 2)
          ai = new VoidAI2Level(this);
        else
          ai = new VoidAI3Level(this);
        createPlayer(ai->createPlayerData(), ai);
    }
}

void Game::replacePlayer(Player* player, const CreatePlayerData& createPlayerData,
                         GameEventListener* gameEventListener)
{
    Q_ASSERT(m_playerList.contains(player));
    if (player->hasController() && !player->isAI())
        throw BadTargetPlayerException();
    if (player->password() != createPlayerData.password)
        throw BadPlayerPasswordException();
    player->update(createPlayerData);
    if (player->hasController())
        player->unregisterGameEventListener();
    player->registerGameEventListener(gameEventListener);
    gameEventManager().onPlayerUpdated(player);
}

void Game::removePlayer(Player* player)
{
    Q_ASSERT(player->game() == this);
    int playerId = player->id();
    if (!m_playerMap.contains(playerId))
        return;
    Q_ASSERT(m_playerMap.contains(playerId)); ///@todo examine this code
    Q_ASSERT(m_playerMap[playerId] == player);
    qDebug(qPrintable(QString("Removing player #%1.").arg(playerId)));

    if (player->isCreator() && m_state == GAMESTATE_WAITINGFORPLAYERS) {
        foreach(Player* p, m_playerList) {
            p->unregisterGameEventListener();
        }
        GameServer::instance().removeGame(this);
        return;
    }
    if (m_state == GAMESTATE_WAITINGFORPLAYERS) {
        m_publicPlayerList.removeAll(&player->publicView());
        m_playerList.removeAll(player);
        m_playerMap.remove(playerId);
        player->unregisterGameEventListener();
        gameEventManager().onPlayerLeavedGame(player);
        if (m_state == GAMESTATE_WAITINGFORPLAYERS)
            checkStartable();
        player->deleteLater();
        return;
    }

    player->unregisterGameEventListener();
    gameEventManager().onPlayerUpdated(player);

    /* CLEANING GAME */
    bool wipeAiOnlyGame = Config::instance().readString("server", "wipe-ai-only-game") == "true";

    bool emptyGame = 1;
    foreach(Player* p, m_playerList) {
        if (wipeAiOnlyGame && p->isAI())
            continue;

        if (p->hasController())
            emptyGame = 0;
    }
    if (emptyGame) {
        GameServer::instance().removeGame(this);
    }
}

void Game::buryPlayer(Player* player, Player* causedBy)
{
    Q_ASSERT(player->lifePoints() <= 0);
    Q_ASSERT(player->isAlive());
    
    if (!(player->isCharmed()) && (player->characterType() == CHARACTER_TOMY_LEE_GHOST)){
            CharacterTomyLeeGhost* ghost =  qobject_cast<CharacterTomyLeeGhost*>(player->character());
            if (!ghost->isAtFirstDead()){
                ghost->setAtFirstDead();
                return;
            }
        }
    
    QList<PlayingCard*> table = player->table();
 
        player->setAlive(0);
        mp_playerReaper->cleanUpCards(player);
        gameEventManager().onPlayerDied(player, causedBy);
        switch(player->role()) {
            case ROLE_SHERIFF:
            case ROLE_DEPUTY:
                m_goodGuysCount--;
                break;
            case ROLE_OUTLAW:
                m_outlawsCount--;
                break;
            case ROLE_RENEGADE:
                m_renegadesCount--;
                break;
            default:
                NOT_REACHED();
        }
        bool reward = false;
        foreach(PlayingCard* card, player->table()){
            if (card->type() == CARD_REWARD){
                reward = true;
            }
        } 
        /// game winning condition check
        if (player->role() == ROLE_SHERIFF) {
             if (m_goodGuysCount == 0 && m_outlawsCount == 0 && m_renegadesCount == 1){
                winningSituation(ROLE_RENEGADE);
            }
            else {
                winningSituation(ROLE_OUTLAW);
            }
        } else if (m_outlawsCount == 0 && m_renegadesCount == 0) {
            winningSituation(ROLE_SHERIFF);
        } else if ((player->role() == ROLE_OUTLAW && causedBy != 0 && causedBy != 0 && causedBy != player) || (causedBy != 0 && !(causedBy->isCharmed()) && causedBy->characterType() == CHARACTER_LOCO)) {
            /// killer draws 3 cards for killing an outlaw
            mp_gameTable->playerDrawFromDeck(causedBy, 3);
         } 
         else if (reward){
             mp_gameTable->playerDrawFromDeck(causedBy, 2);
         }
         else if (player->role() == ROLE_DEPUTY && causedBy != 0 && causedBy->role() == ROLE_SHERIFF) {
            /// sheriff killed his deputy and has to cancel all his cards
            foreach(PlayingCard* card, causedBy->hand()){
                gameTable().cancelCard(card);
            }
            foreach(PlayingCard* card, causedBy->table()){
                gameTable().cancelCard(card);
            }
        }
    
}

void Game::winningSituation(PlayerRole winners)
{
    m_state = GAMESTATE_FINISHED;
    foreach(Player* player, m_playerList) {
        switch(winners) {
        case ROLE_SHERIFF:
            if (player->role() == ROLE_SHERIFF ||
                player->role() == ROLE_DEPUTY)
                player->setWinner(1);
            break;
        case ROLE_OUTLAW:
            if (player->role() == ROLE_OUTLAW)
                player->setWinner(1);
            break;
        case ROLE_RENEGADE:
            if (player->role() == ROLE_RENEGADE &&
                player->isAlive())
                player->setWinner(1);
            break;
        default:
            NOT_REACHED();
        }
    }
    gameEventManager().onGameFinished();
}

void Game::startGame(Player* player, int n)
{
    if (player->id() != mp_gameInfo->creatorId()) {
        throw BadPlayerException(player->id());
    }
    if (m_state != GAMESTATE_WAITINGFORPLAYERS) {
        throw BadGameStateException();
    }
    if (!m_startable) {
        throw BadGameStateException();
    }
    m_state = GAMESTATE_PLAYING;
    if (mp_gameInfo->hasShufflePlayers())
        shufflePlayers();

    setRolesAndCharacters(n);

    gameEventManager().onGameStarted();
    mp_gameTable->prepareGame(GameServer::instance().cardFactory());
    mp_gameCycle->start();
}


void Game::sendChatMessage(Player* player, const QString& message)
{
    gameEventManager().onChatMessage(player, message);
}

void Game::installNewRenegade(){
    m_renegadesCount++;
}

void Game::reversePlayerList(){
    std::reverse(m_playerList.begin(), m_playerList.end());
}

void Game::swapPlayers(int p1, int p2){
    if (p1 < 0) throw BadPlayerException(p1);
    if (p2 < 0) throw BadPlayerException(p2);
    if (p1 >= m_playerList.size()) throw BadPlayerException(p1);
    if (p2 >= m_playerList.size()) throw BadPlayerException(p2);
    m_playerList.swap(p1, p2);
}

void Game::checkStartable()
{
    bool newStartable;
    if (m_playerList.count() >= mp_gameInfo->minPlayers() &&
            m_playerList.count() <= mp_gameInfo->maxPlayers())
        newStartable = 1;
    else
        newStartable = 0;
    if (m_startable != newStartable && mp_gameInfo->creatorId() != 0) {
        m_playerMap[mp_gameInfo->creatorId()]->gameEventListener()->onGameStartabilityChanged(newStartable);
    }
    m_startable = newStartable;
}

void Game::shufflePlayers()
{
    shuffleList(m_playerList);
    m_publicPlayerList.clear();
    foreach(Player* player, m_playerList) {
        m_publicPlayerList.append(&player->publicView());
    }
}

void Game::setRolesAndCharacters(int n)
{
    QList<PlayerRole> roles = getRoleList();
    CharacterList characters = CharacterList(this, m_playerList.size());
    shuffleList(roles);
    //Also CharacterList must be shuffled!
    //CharacterList is shuffled
    QListIterator<Player*> pIt(m_playerList);
    QListIterator<PlayerRole> rIt(roles);
    QListIterator<CharacterBase*> cIt(characters);
    int i = 0;
    m_goodGuysCount = m_outlawsCount = m_renegadesCount = 0;
    try {
      while(pIt.hasNext() && rIt.hasNext() && cIt.hasNext())
      {   
          pIt.peekNext()->setRoleAndCharacter(cIt.peekNext(), rIt.peekNext());
        switch(rIt.peekNext()) {
            case ROLE_SHERIFF:
            case ROLE_DEPUTY:
                m_goodGuysCount++;
                break;
            case ROLE_OUTLAW:
                m_outlawsCount++;
                break;
            case ROLE_RENEGADE:
                m_renegadesCount++;
                break;
            default:
                NOT_REACHED();
        }
        i++;
        pIt.next(); rIt.next(); cIt.next();
      }
      
    }
    catch (const std::invalid_argument& exp){
      std::cout << exp.what();
    }
}

QList<PlayerRole> Game::getRoleList()
{
    static const char* roleSets[] = {"", "S", "SB", "SRB", "SBBR", "SVBBR", "SVBBBR", "SVVBBBR", "SVVBBBRR"};
    QList<PlayerRole> res;
    const char* i = roleSets[m_playerList.count()];
    while(*i != '\0')
    {
        switch(*i)
        {
            case 'S': res.append(ROLE_SHERIFF); break;
            case 'B': res.append(ROLE_OUTLAW); break;
            case 'V': res.append(ROLE_DEPUTY); break;
            case 'R': res.append(ROLE_RENEGADE); break;
        }
        ++i;
    }
    return res;
}


