/*************************************************************************** POCKET_BANK
 *   Copyright (C) 2008 by MacJariel                                       *
 *   echo "badmailet@gbalt.dob" | tr "edibmlt" "ecrmjil"                   *
 *                                                                         *
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

#include <QTcpSocket>
#include <QHostAddress>

#include "client.h"
#include "publicgameview.h"
#include "privateplayerview.h"
#include "playingcard.h"
#include "parser/parserstructs.h"
#include "gameeventmanager.h"
#include "weaponcard.h"

#include "voidai.h"

Client::Client(QObject* parent, int id, QTcpSocket* socket):
        QObject(parent),
        m_id(id),
        mp_playerCtrl(0),
        mp_socket(socket)
{ 
    Q_ASSERT(m_id != 0);
    mp_parser = new Parser(this, socket);
    connect(mp_parser,  SIGNAL(terminated()),
            this,       SLOT(onParserTerminated()));
    connect(mp_parser,  SIGNAL(sigQueryServerInfo(QueryResult)),
            this,       SLOT(onQueryServerInfo(QueryResult)));
    connect(mp_parser,  SIGNAL(sigQueryGameInfo(int, const QueryResult&)),
            this,       SLOT(onQueryGameInfo(int, const QueryResult&)));
    connect(mp_parser,  SIGNAL(sigQueryGameInfoList(const QueryResult&)),
            this,       SLOT(onQueryGameInfoList(const QueryResult&)));
    connect(mp_parser,  SIGNAL(sigActionCreateGame(const CreateGameData&, const CreatePlayerData&)),
            this,       SLOT(onActionCreateGame(const CreateGameData&, const CreatePlayerData&)));
    connect(mp_parser,  SIGNAL(sigActionJoinGame(int, int, const QString&, const CreatePlayerData&)),
            this,       SLOT(onActionJoinGame(int, int, const QString&, const CreatePlayerData&)));
    connect(mp_parser,  SIGNAL(sigActionLeaveGame()),
            this,       SLOT(onActionLeaveGame()));
    connect(mp_parser,  SIGNAL(sigActionStartGame()),
            this,       SLOT(onActionStartGame()));
    connect(mp_parser,  SIGNAL(sigActionDrawCard()),
            this,       SLOT(onActionDrawCard()));
    connect(mp_parser,  SIGNAL(sigActionPlayCard(const ActionPlayCardData&)),
            this,       SLOT(onActionPlayCard(const ActionPlayCardData&)));
    connect(mp_parser,  SIGNAL(sigActionUseAbility(const ActionUseAbilityData&)),
            this,       SLOT(onActionUseAbility(const ActionUseAbilityData&)));
    connect(mp_parser,  SIGNAL(sigActionEndTurn()),
            this,       SLOT(onActionEndTurn()));
    connect(mp_parser,  SIGNAL(sigActionPass()),
            this,       SLOT(onActionPass()));
    connect(mp_parser,  SIGNAL(sigActionDiscard(int)),
            this,       SLOT(onActionDiscard(int)));
    connect(mp_parser,  SIGNAL(sigActionChatMessage(const QString&)),
            this,       SLOT(onActionChatMessage(const QString&)));
}

Client::~Client()
{
    emit disconnected(m_id);
    mp_socket->deleteLater();
}

int Client::id() const
{
    return m_id;
}

int Client::gameId() const
{
    if (!mp_playerCtrl)
        return 0;
    return mp_publicGameView->id();
}

int Client::playerId() const
{
    if (!mp_playerCtrl)
        return 0;
    return mp_playerCtrl->privatePlayerView().id();
}

QString Client::address() const
{
    return mp_socket->peerAddress().toString();
}

QTcpSocket* Client::socket()
{
    return mp_socket;
}

void Client::onActionCreateGame(const CreateGameData& createGameData, const CreatePlayerData& createPlayerData)
{
    if (isInGame()) {
        // TODO: respond with error
        return;
    }
    try {
		PlayerCtrl::createGame(createGameData, createPlayerData, this);
	} catch (GameException& e) {
        qDebug() << "Client::onActionCreateGame - exception:";
        e.debug();
	}
}


void Client::onActionJoinGame(int gameId, int playerId, QString gamePassword, const CreatePlayerData& player)
{
    if (isInGame()) {
        // TODO: respond with error
        return;
    }
    try {
        if  (playerId == 0) {
            PlayerCtrl::joinGame(gameId, gamePassword, player, this);
        } else {
            PlayerCtrl::replacePlayer(gameId, playerId, gamePassword, player, this);
        }
    } catch (GameException& e) {
        qDebug() << "Client::onActionJoinGame - exception:";
        e.debug();
    }
}

void Client::onActionLeaveGame()
{
    if (!isInGame()) {
        return;
    }
	try {
		mp_playerCtrl->disconnect();
	} catch (GameException& e) {
        qDebug() << "Client::onActionLeaveGame - exception:";
        e.debug();
	}
}

void Client::onActionStartGame()
{
    if (!isInGame()) {
        return;
    }
	try {
	    mp_playerCtrl->startGame();
	} catch (GameException& e) {
        qDebug() << "Client::onActionStartGame - exception:";
        e.debug();
	}
}

void Client::onActionDrawCard()
{
    if (mp_playerCtrl == 0)
        return;

    try {
        mp_playerCtrl->draw();
    } catch (GameException& e) {
        qDebug() << "Client::onActionDrawCard - exception:";
        e.debug();
    }
}




void Client::onActionPlayCard(const ActionPlayCardData& actionPlayCardData)
{
    if (mp_playerCtrl == 0)
        return;

    qDebug("[CLIENT]   onActionPlayCard");
    PlayingCard* playedCard = mp_playerCtrl->privatePlayerView().card(actionPlayCardData.playedCardId);
    if (playedCard == 0) {
        qDebug(qPrintable(QString("[CLIENT]   Card '%1' not found!").arg(actionPlayCardData.playedCardId)));
        // @todo feedback
        return;
    }
    try {
        switch (actionPlayCardData.type) {
        case ActionPlayCardData::PLAYCARD_SIMPLE:
            qDebug("PLAYCARD_SIMPLE");
            mp_playerCtrl->playCard(playedCard);
            break;
        case ActionPlayCardData::PLAYCARD_PLAYER:
            qDebug("PLAYCARD_PLAYER");
        case ActionPlayCardData::PLAYCARD_HAND:{
            qDebug("PLAYCARD_HAND"); 
                int targetPlayerId = (actionPlayCardData.type == ActionPlayCardData::PLAYCARD_PLAYER) ?
                                     actionPlayCardData.targetPlayerId :
                                     actionPlayCardData.targetHandId;

                PublicPlayerView* targetPlayer =
                        mp_publicGameView->publicPlayerView(targetPlayerId);

                        qDebug() << "PLAYCARD_CARD targetPlayerId: " << targetPlayerId;
                        qDebug() << "PLAYCARD_CARD playedCard: " << playingCardTypeToString(playedCard->type());
                if (targetPlayer == 0) {
                    qDebug(qPrintable(QString("[CLIENT]   Target player '%1' not exist!").arg(actionPlayCardData.targetPlayerId)));
                    // @todo feedback
                    return;
                }
                mp_playerCtrl->playCard(playedCard, targetPlayer);
            } break;
        case ActionPlayCardData::PLAYCARD_CARD: {
            qDebug("PLAYCARD_CARD");
            qDebug() << "Playing type card " << playingCardTypeToString(playedCard->type());
            int targetCardId = actionPlayCardData.targetCardId;
            PlayingCard* card = mp_playerCtrl->card(targetCardId);
            if (card == 0) {
                qDebug(qPrintable(QString("[CLIENT]   Target card '%1' not exist!").arg(targetCardId)));
                // @todo feedback
                return;
            }
            mp_playerCtrl->playCard(playedCard, card);
            break;
        }
        case ActionPlayCardData::PLAYCARD_CARD_AND_PLAYER: {
            qDebug("PLAYCARD_CARD_AND_PLAYER");
            int targetCardId2 = actionPlayCardData.targetCardId;
            PlayingCard* card2 = mp_playerCtrl->card(targetCardId2);
            if (card2 == 0) {
                qDebug(qPrintable(QString("[CLIENT]   Target card '%1' not exist!").arg(targetCardId2)));
                // @todo feedback
                return;
            }
            int targetPlayerId2 = actionPlayCardData.targetPlayerId;

            PublicPlayerView* targetPlayer2 =
            mp_publicGameView->publicPlayerView(targetPlayerId2);

            if (targetPlayer2 == 0) {
                qDebug(qPrintable(QString("[CLIENT]   Target player '%1' not exist!").arg(actionPlayCardData.targetPlayerId)));
                // @todo feedback
                return;
            }
            mp_playerCtrl->playCard(playedCard, card2, targetPlayer2);
            break;   
          }
          case ActionPlayCardData::PLAYCARD_CARDS: {
            qDebug("PLAYCARD_CARDS");
            QList<int> targetCardsId = actionPlayCardData.targetCardsId;
            QList<PlayingCard*> cards = QList<PlayingCard*>();
            foreach(int cardId, targetCardsId) {
                PlayingCard* card = mp_playerCtrl->card(cardId); 
                if (card == 0) {
                    qDebug(qPrintable(QString("[CLIENT]   Target card '%1' not exist!").arg(cardId)));
                    // @todo feedback
               }
               else {
                    cards.push_back(card);  
                    qDebug() << " Target card id: ";
                    qDebug() << cardId << " "; 
                 }
            } 
               
        
//               if (playedCard->type() == CARD_BRAWL){
//                   Game* game = mp_playerCtrl->theSheriff()->game();
//                   foreach (Player* player, game->playerList()){
//                      if (player->isAlive()){
//                          bool add = true;
//                          foreach (PlayingCard* card, cards){
//                              if (card->owner() == player){
//                                  add = false;
//                              }
//                          } 
//                          if (add){
//                              if (!(player->hand().empty())){
//                                cards.push_back(player->getRandomCardFromHand()); 
//                              }
//                              else {
//                                  if (!(player->table().empty())){
//                                    cards.push_back(player->getRandomCardFromTable());   
//                                 }
//                                 else {
//                                     continue;
//                                 }
//                             }
//                          }
//                      }
//                 }
//             }
//             if (playedCard->type() == CARD_JAMES_DOUGALL){
//                 Player* player2 = cards.at(2)->owner();
//                 WeaponCard* weaponCard = qobject_cast<WeaponCard*>(playedCard);
//                 weaponCard->play(cards, player2);
//             }
//             else {
            mp_playerCtrl->playCard(playedCard, cards);
//            }
            break;
        }
        case ActionPlayCardData::PLAYCARD_PLAYERS:{
            qDebug("PLAYCARD_PLAYERS");
             QList<int> targetPlayersId = actionPlayCardData.targetPlayersId;
            QList<PublicPlayerView*> players = QList<PublicPlayerView*>();
            foreach(int playerId, targetPlayersId) {
                PublicPlayerView* player = getPlayer(playerId); 
                if (player == 0) {
                    qDebug(qPrintable(QString("[CLIENT]   Target player '%1' not exist!").arg(playerId)));
                    // @todo feedback
                    //getRandomCardFromHand();
                    //return;
               }
               else {
                  players.push_back(player);  
               } 
            }
            mp_playerCtrl->playCard(playedCard, players);
            break;
        }
        }
    } catch (GameException& e) {
        qDebug("[CLIENT]: onActionPlayCard - exception:");
        e.debug();
        return;
    }
}

void Client::onActionUseAbility(const ActionUseAbilityData& actionUseAbilityData)
{
    if (mp_playerCtrl == 0)
        return;

    try {
        switch(actionUseAbilityData.type) {
            case ActionUseAbilityData::TypeSimple: {
                mp_playerCtrl->useAbility();
                break;
            }
            case ActionUseAbilityData::TypePlayer: {
                PublicPlayerView* targetPlayer = getPlayer(actionUseAbilityData.targetPlayerId);
                if (targetPlayer == 0)
                    return;
                mp_playerCtrl->useAbility(targetPlayer);
                break;
            }
            case ActionUseAbilityData::TypeCards: {
                QList<PlayingCard*> cards = getCards(actionUseAbilityData.targetCardsId);
                mp_playerCtrl->useAbility(cards);
                break;
            }
            case ActionUseAbilityData::TypeCardsAndPLayer: {
                QList<PlayingCard*> cards = getCards(actionUseAbilityData.targetCardsId);
                PublicPlayerView* targetPlayer = getPlayer(actionUseAbilityData.targetPlayerId);
                if (targetPlayer == 0){
                    qDebug() << "targetPlayer is NULL.";
                    return;
                }
                mp_playerCtrl->useAbility(cards, targetPlayer);
                break;
            }
        }
    } catch (GameException& e) {
        qDebug("[CLIENT]: onActionUseAbility - exception:");
        e.debug();
        return;
    }
}

void Client::onActionEndTurn()
{
    if (mp_playerCtrl == 0)
        return;

    try {
        mp_playerCtrl->finishTurn();
    } catch (GameException& e) {
        qDebug("[CLIENT]: onActionEndTurn - exception:");
        e.debug();
        return;
    }
}

void Client::onActionPass()
{
    if (mp_playerCtrl == 0)
        return;

    try {
        mp_playerCtrl->pass();
    } catch (GameException& e) {
        qDebug("[CLIENT]: onActionPass - exception:");
        e.debug();
        return;
    }
}

void Client::onActionDiscard(int cardId)
{
    if (mp_playerCtrl == 0)
        return;

    try {
        PlayingCard* card = mp_playerCtrl->privatePlayerView().card(cardId);
        if (card == 0) {
            qDebug("Cannot discard unknown card.");
            return;
        }
        mp_playerCtrl->discardCard(card);
    } catch (GameException& e) {
        qDebug("[CLIENT]: onActionDiscard - exception:");
        e.debug();
        return;
    }
}

void Client::onActionChatMessage(const QString& message)
{
    if (mp_playerCtrl == 0){
        return;
    }
	try {
		mp_playerCtrl->sendChatMessage(message);
	} catch (GameException& e) {
        qDebug() << "Client::onActionChatMessage - exception:";
        e.debug();
	}
}


void Client::onQueryServerInfo(QueryResult result)
{
    result.sendData(PlayerCtrl::serverInfo());
}

void Client::onQueryGameInfo(int gameId, QueryResult result)
{
    try {
        const PublicGameView& publicGameView = PlayerCtrl::publicGameView(gameId);
        GameInfoData gameInfoData = publicGameView.gameInfoData();
        result.sendData(gameInfoData);
    } catch (GameException& e) {
        qDebug() << "Client::onQueryGameInfo - exception:";
        e.debug();
    }
}

void Client::onQueryGameInfoList(QueryResult result)
{
    GameInfoListData gamesInfo;
    foreach (const PublicGameView* publicGameView, PlayerCtrl::publicGameList()) {
        gamesInfo.append(publicGameView->gameInfoData());
    }
    result.sendData(gamesInfo);
}

void Client::onParserTerminated()
{
    mp_parser = 0;
    if (mp_playerCtrl) {
        mp_playerCtrl->disconnect();
    }
    deleteLater();
}



////////////////////////////////////////////
// The AbstractPlayerController interface //
////////////////////////////////////////////


void Client::onHandlerRegistered(const PublicGameView* publicGameView, PlayerCtrl* playerCtrl)
{
    if (mp_parser == 0) return;
    mp_playerCtrl = playerCtrl; 
    mp_publicGameView = publicGameView;
    mp_parser->eventEnterGameMode(mp_publicGameView->id(),
                                  mp_publicGameView->name(),
                                  CLIENT_PLAYER); //@todo: spectator
    if (mp_publicGameView->gameState() == GAMESTATE_WAITINGFORPLAYERS) 
    onGameSync();
}

void Client::onHandlerUnregistered()
{
    mp_playerCtrl = 0;
    mp_publicGameView = 0;
    if (mp_parser == 0) return;
    mp_parser->eventExitGameMode();
}

void Client::onGameStartabilityChanged(bool isStartable)
{
    if (mp_parser == 0) return;
    mp_parser->eventGameCanBeStarted(isStartable);
}

void Client::onChatMessage(PublicPlayerView& publicPlayerView, const QString& message)
{
    if (mp_parser == 0) return;
    mp_parser->eventChatMessage(publicPlayerView.id(),
                                publicPlayerView.name(),
                                message);
}

void Client::onGameSync()
{
    if (mp_parser == 0) return;
    GameSyncData gameSyncData;
    gameSyncData.id = mp_publicGameView->id();
    gameSyncData.name = mp_publicGameView->name();
    gameSyncData.isCreator = mp_playerCtrl->privatePlayerView().isCreator();
    gameSyncData.state = mp_publicGameView->gameState();
        
    if (mp_publicGameView->graveyardTop() == 0) {
        gameSyncData.graveyard = CardData();
    }
    else {
        gameSyncData.graveyard = mp_publicGameView->graveyardTop()->cardData();
    }
    foreach (const PublicPlayerView* p, mp_publicGameView->publicPlayerList()){
        gameSyncData.players.append(p->publicPlayerData());
    }
    gameSyncData.localPlayer = mp_playerCtrl->privatePlayerView().privatePlayerData();
    gameSyncData.gameContext = mp_publicGameView->gameContextData();
    foreach (const PlayingCard* c, mp_publicGameView->selection()){
        gameSyncData.selection.append(c->cardData());
    }
    mp_parser->eventGameSync(gameSyncData);

    if (gameSyncData.isCreator && gameSyncData.state == GAMESTATE_WAITINGFORPLAYERS){
        onGameStartabilityChanged(mp_publicGameView->canBeStarted());
    }
}


void Client::onPlayerJoinedGame(PublicPlayerView& publicPlayerView)
{
    if (mp_parser == 0) return;
    if (publicPlayerView.id() == mp_playerCtrl->privatePlayerView().id())
        return;
    mp_parser->eventPlayerJoinedGame(publicPlayerView.publicPlayerData());
}

void Client::onPlayerLeavedGame(PublicPlayerView& leavingPlayer)
{
    if (mp_parser == 0) return;
    mp_parser->eventPlayerLeavedGame(leavingPlayer.id());
}

void Client::onPlayerUpdated(PublicPlayerView& player)
{
    if (mp_parser == 0) return;
    mp_parser->eventPlayerUpdate(player.publicPlayerData());
}

void Client::onPlayerDied(PublicPlayerView& player, PublicPlayerView* causedBy)
{
    //qDebug() << "Client::onPlayerDied(PublicPlayerView&, PublicPlayerView*) 1";
    
    if (mp_parser == 0) return;

    //qDebug() << "Client::onPlayerDied(PublicPlayerView&, PublicPlayerView*) 2";
    GameMessage message;
    message.type = GAMEMESSAGE_PLAYERDIED;
    message.player = player.id();
    message.causedBy = 0;
    if (causedBy){
      message.causedBy = causedBy->id();
    }
    //qDebug() << "Client::onPlayerDied(PublicPlayerView&, PublicPlayerView*) 3";
    mp_parser->eventGameMessage(message);
    //qDebug() << "Client::onPlayerDied(PublicPlayerView&, PublicPlayerView*) 4";

    int         playerId = player.id();
    PlayerRole  role     = player.role();
    Q_ASSERT(role != ROLE_UNKNOWN);
    //qDebug() << "Client::onPlayerDied(PublicPlayerView&, PublicPlayerView*) 5";
    mp_parser->eventPlayerDied(playerId, role);
    //qDebug() << "Client::onPlayerDied(PublicPlayerView&, PublicPlayerView*) 6";
}


void Client::onPlayerDied(PublicPlayerView& player)
{
    //qDebug() << "Client::onPlayerDied(PublicPlayerView&) 1";
    if (mp_parser == 0) return;

    //qDebug() << "Client::onPlayerDied(PublicPlayerView&) 2";
    GameMessage message;
    message.type = GAMEMESSAGE_PLAYERDIED;
    message.player = player.id();
    message.causedBy = 0;
    //qDebug() << "Client::onPlayerDied(PublicPlayerView&) 3";
    mp_parser->eventGameMessage(message);
    //qDebug() << "Client::onPlayerDied(PublicPlayerView&) 4";

    int         playerId = player.id();
    PlayerRole  role     = player.role();
    Q_ASSERT(role != ROLE_UNKNOWN);
    //qDebug() << "Client::onPlayerDied(PublicPlayerView&) 5";
    mp_parser->eventPlayerDied(playerId, role);
    //qDebug() << "Client::onPlayerDied(PublicPlayerView&) 6";
}

void Client::onGameStarted()
{
    if (mp_parser == 0) return;
    GameMessage message;
    message.type = GAMEMESSAGE_GAMESTARTED;
    mp_parser->eventGameMessage(message);


    /*
    StructGame structGame = mp_publicGameView->structGame();
    StructPlayerList structPlayerList;
    const PrivatePlayerView* privatePlayer = &mp_playerCtrl->privatePlayerView();
    foreach(const PublicPlayerView* player, mp_publicGameView->publicPlayerList()) {
        if (player->id() == privatePlayer->id())
            player = privatePlayer;
        structPlayerList.append(player->structPlayer());
    }
    mp_parser->eventStartGame(structGame, structPlayerList);
    */
}

void Client::onGameFinished()
{
    if (mp_parser == 0) return;
    GameMessage message;
    message.type = GAMEMESSAGE_GAMEFINISHED;
    mp_parser->eventGameMessage(message);

    onGameSync();
}

void Client::onPlayerDrawFromDeck(PublicPlayerView& player, QList< PlayingCard*> cards, bool revealCards)
{
    if (mp_parser == 0) return;
    Q_UNUSED(revealCards);
    GameMessage message = GameMessage();
    message.type = GAMEMESSAGE_PLAYERDRAWFROMDECK;
    message.player = player.id();
    foreach( PlayingCard* card, cards) {
        if (card != 0) {
          message.cards.append(card->cardData()); //segfault
        }
    }
    mp_parser->eventGameMessage(message);


    foreach ( PlayingCard* card, cards) { 
        CardMovementData x;
        x.pocketTypeFrom = POCKET_DECK;
        x.pocketTypeTo   = POCKET_HAND;
        x.playerTo       = player.id();
        if (card != 0){
            x.card = card->cardData();
        }
        mp_parser->eventCardMovement(x);
    }
        getPlayer(playerId())->player()->game()->gameEventManager().onPlayerUpdated(getPlayer(playerId())->player());

}

void Client::onPlayerDrawFromGraveyard(PublicPlayerView& player, const PlayingCard* card, const PlayingCard* nextCard)
{
    if (mp_parser == 0) return;

    GameMessage message;
    message.type = GAMEMESSAGE_PLAYERDRAWFROMGRAVEYARD;
    message.player = player.id();
    message.card = card->cardData();
    mp_parser->eventGameMessage(message);

    CardMovementData x;
    x.pocketTypeFrom = POCKET_GRAVEYARD;
    x.pocketTypeTo   = POCKET_HAND;
    x.playerTo       = player.id();
    x.card           = card->cardData();
    x.secondCard     = nextCard->cardData();
    mp_parser->eventCardMovement(x);
    getPlayer(playerId())->player()->game()->gameEventManager().onPlayerUpdated(getPlayer(playerId())->player());

}

void Client::onPlayerDiscardCard(PublicPlayerView& player, const PlayingCard* card, PocketType pocketFrom)
{
    if (mp_parser == 0) return;

    GameMessage message;
    message.type = GAMEMESSAGE_PLAYERDISCARDCARD;
    message.player = player.id();
    message.card = card->cardData();
    mp_parser->eventGameMessage(message);

    CardMovementData x;
    x.pocketTypeFrom = pocketFrom;
    x.pocketTypeTo   = POCKET_GRAVEYARD;
    x.playerFrom     = player.id();
    x.card           = card->cardData();
    mp_parser->eventCardMovement(x);
    getPlayer(playerId())->player()->game()->gameEventManager().onPlayerUpdated(getPlayer(playerId())->player());

}

void Client::onPlayerPlayCard(PublicPlayerView& player, const PlayingCard* card)
{
    if (mp_parser == 0) return;

    GameMessage message;
    message.type = GAMEMESSAGE_PLAYERPLAYCARD;
    message.player = player.id();
    message.card = card->cardData();
    mp_parser->eventGameMessage(message);

    CardMovementData x;
    x.pocketTypeFrom = POCKET_HAND;
    x.pocketTypeTo   = POCKET_GRAVEYARD;
    x.playerFrom     = player.id();
    x.card           = card->cardData();
    
    if (card->color() != COLOR_BROWN){ 
       if (card->pocket() == POCKET_GRAVEYARD){
         x.pocketTypeFrom = POCKET_TABLE;
       }
      if (card->pocket() == POCKET_TABLE){
        x.pocketTypeFrom = POCKET_TABLE;
      }
    }
    
    mp_parser->eventCardMovement(x);
    getPlayer(playerId())->player()->game()->gameEventManager().onPlayerUpdated(getPlayer(playerId())->player());

}

void Client::onPlayerPlayCard(PublicPlayerView& player, PlayingCard* card1, PlayingCard* card2){
    
    if (mp_parser == 0) return;

    Player* targetPlayer = card2->owner();
    card1->play(card2);
    
    GameMessage message;
    message.type = GAMEMESSAGE_PLAYERPLAYCARD;
    message.player = player.id();
    message.card = card1->cardData();
    mp_parser->eventGameMessage(message);

    CardMovementData x;
    x.pocketTypeFrom = POCKET_HAND;
    x.pocketTypeTo   = POCKET_GRAVEYARD;
    x.playerFrom     = player.id();
    x.card           = card1->cardData();
    
    CardMovementData y;
    y.pocketTypeFrom = POCKET_HAND;
    y.pocketTypeTo   = POCKET_GRAVEYARD;
    y.playerFrom     = player.id();
    y.card           = card2->cardData();
    
    if (card1->color() != COLOR_BROWN){
       if (card1->pocket() == POCKET_GRAVEYARD){
         x.pocketTypeFrom = POCKET_TABLE;
       }
      if (card1->pocket() == POCKET_TABLE){
        x.pocketTypeFrom = POCKET_TABLE;
      }
    }
    
     if (card2->color() != COLOR_BROWN){
       QList<PlayingCard*> table = mp_playerCtrl->privatePlayerView().table();
       if (card2->pocket() == POCKET_GRAVEYARD){
         y.pocketTypeFrom = POCKET_TABLE;
       }
       if (card2->pocket() == POCKET_TABLE){
         y.pocketTypeFrom = POCKET_TABLE;
       }
     }
//     
     if ((card1->type() == CARD_PANIC) || (card1->type() == CARD_CATBALOU)){
         player.player()->addAdversary(&(targetPlayer->publicView()));
     }

    mp_parser->eventCardMovement(x);
    mp_parser->eventCardMovement(y);
    getPlayer(playerId())->player()->game()->gameEventManager().onPlayerUpdated(getPlayer(playerId())->player());


}

void Client::onPlayerPlayCard(PublicPlayerView& player, const PlayingCard* card, PublicPlayerView& target)
{
    if (mp_parser == 0) return;

    GameMessage message;
    message.type = GAMEMESSAGE_PLAYERPLAYCARD;
    message.player = player.id();
    message.card = card->cardData();
    message.targetPlayer = target.id();
    mp_parser->eventGameMessage(message);

    CardMovementData x;
    x.pocketTypeFrom = POCKET_HAND;
    x.pocketTypeTo   = POCKET_GRAVEYARD;
    x.playerFrom     = player.id();
    x.card           = card->cardData();
    
    if (card->color() != COLOR_BROWN){
       if (card->pocket() == POCKET_GRAVEYARD){
         x.pocketTypeFrom = POCKET_TABLE;
       }
      if (card->pocket() == POCKET_TABLE){
        x.pocketTypeFrom = POCKET_TABLE;
      }
    }
    
    if ((card->type() == CARD_BANG) || (card->type() == CARD_DUEL) || (card->type() == CARD_JAIL)){
         player.player()->addAdversary(&target);
    } 
    
    mp_parser->eventCardMovement(x);
    getPlayer(playerId())->player()->game()->gameEventManager().onPlayerUpdated(getPlayer(playerId())->player());

}

void Client::onPlayerPlayCard(PublicPlayerView& player, const PlayingCard* card, const PlayingCard* target, PublicPlayerView* targetPlayer)
{
    if (mp_parser == 0) return;

    Q_UNUSED(target);

    GameMessage message;
    message.type = GAMEMESSAGE_PLAYERPLAYCARD;
    message.player = player.id();
    message.card = card->cardData();
    message.targetCard = card->cardData();
    message.targetPlayer = targetPlayer ? targetPlayer->id() : 0;
    mp_parser->eventGameMessage(message);

    CardMovementData x;
    x.pocketTypeFrom = POCKET_HAND;
    x.pocketTypeTo   = POCKET_GRAVEYARD;
    x.playerFrom     = player.id();
    x.card           = card->cardData();
    
    if (card->color() != COLOR_BROWN){
       if (card->pocket() == POCKET_GRAVEYARD){
         x.pocketTypeFrom = POCKET_TABLE;
       }
      if (card->pocket() == POCKET_TABLE){
        x.pocketTypeFrom = POCKET_TABLE;
      }
    }
    
    mp_parser->eventCardMovement(x);
    getPlayer(playerId())->player()->game()->gameEventManager().onPlayerUpdated(getPlayer(playerId())->player());

}

void Client::onPlayerPlayCardOnTable(PublicPlayerView& player, const PlayingCard* card, PublicPlayerView& targetPlayer)
{
    if (mp_parser == 0) return;

    GameMessage message;
    message.type = GAMEMESSAGE_PLAYERPLAYCARD;
    message.player = player.id();
    message.card = card->cardData();
    message.targetPlayer = (targetPlayer.id() != mp_playerCtrl->privatePlayerView().id()) ?
                           targetPlayer.id() : 0;
    mp_parser->eventGameMessage(message);

    CardMovementData x;
    x.pocketTypeFrom = POCKET_HAND;
    x.pocketTypeTo   = POCKET_TABLE;
    x.playerFrom     = player.id();
    x.playerTo       = targetPlayer.id();
    x.card           = card->cardData();
    mp_parser->eventCardMovement(x);
    getPlayer(playerId())->player()->game()->gameEventManager().onPlayerUpdated(getPlayer(playerId())->player());

}

void Client::onPassTableCard(PublicPlayerView& player, const PlayingCard* card, PublicPlayerView& targetPlayer)
{
    if (mp_parser == 0) return;
    CardMovementData x;
    x.pocketTypeFrom = POCKET_TABLE;
    x.pocketTypeTo   = POCKET_TABLE;
    x.playerFrom     = player.id();
    x.playerTo       = targetPlayer.id();
    x.card           = card->cardData();
    mp_parser->eventCardMovement(x);
    getPlayer(playerId())->player()->game()->gameEventManager().onPlayerUpdated(getPlayer(playerId())->player());

}

void Client::onPlayerRespondWithCard(PublicPlayerView& player, const PlayingCard* card)
{
    if (mp_parser == 0) return;

    GameMessage message;
    message.type = GAMEMESSAGE_PLAYERRESPONDWITHCARD;
    message.player = player.id();
    message.card = card->cardData();
    mp_parser->eventGameMessage(message);

    CardMovementData x;
    x.pocketTypeFrom = POCKET_HAND;
    x.pocketTypeTo   = POCKET_GRAVEYARD;
    x.playerFrom     = player.id(); 
    x.card           = card->cardData();
    if (card->color() != COLOR_BROWN){
      if (card->pocket() == POCKET_GRAVEYARD){
         x.pocketTypeFrom = POCKET_TABLE;
       }
      if (card->pocket() == POCKET_TABLE){
        x.pocketTypeFrom = POCKET_TABLE;
      }
    }
    mp_parser->eventCardMovement(x);
    getPlayer(playerId())->player()->game()->gameEventManager().onPlayerUpdated(getPlayer(playerId())->player());

}

void Client::onPlayerPass(PublicPlayerView& player)
{
    GameMessage message;
    message.type = GAMEMESSAGE_PLAYERPASS;
    message.player = player.id();
    mp_parser->eventGameMessage(message);

    if (mp_parser == 0) return;
}

void Client::onDrawIntoSelection(QList<const PlayingCard*> cards)
{
    if (mp_parser == 0) return;
    foreach (const PlayingCard* card, cards) {
        CardMovementData x;
        x.pocketTypeFrom = POCKET_DECK;
        x.pocketTypeTo   = POCKET_SELECTION;
        x.playerTo       = 0;
        if (card != 0)
            x.card = card->cardData();
        mp_parser->eventCardMovement(x);
    }
}

void Client::onPlayerPickFromSelection(PublicPlayerView& player, const PlayingCard* card)
{
    if (mp_parser == 0) return;

    GameMessage message;
    message.type = GAMEMESSAGE_PLAYERPICKFROMSELECTION;
    message.player = player.id();
    message.card = card->cardData();
    mp_parser->eventGameMessage(message);

    CardMovementData x;
    x.pocketTypeFrom = POCKET_SELECTION;
    x.pocketTypeTo   = POCKET_HAND;
    x.playerFrom     = 0;
    x.playerTo       = player.id();
    x.card           = card->cardData();
    mp_parser->eventCardMovement(x);
}

void Client::onUndrawFromSelection(const PlayingCard* card)
{
    if (mp_parser == 0) return;
    CardMovementData x;
    x.pocketTypeFrom = POCKET_SELECTION;
    x.pocketTypeTo   = POCKET_DECK;
    x.playerFrom     = 0;
    x.playerTo       = 0;
    if (card != 0)
        x.card = card->cardData();
    mp_parser->eventCardMovement(x);
}

void Client::onPlayerCheckDeck(PublicPlayerView& player, const PlayingCard* checkedCard, const PlayingCard* causedBy, bool checkResult)
{
    if (mp_parser == 0) return;

    GameMessage message;
    message.type = GAMEMESSAGE_PLAYERCHECKDECK;
    message.player = player.id();
    message.targetCard = checkedCard->cardData();
    message.card = causedBy->cardData();
    message.checkResult = checkResult;
    mp_parser->eventGameMessage(message);

}

void Client::onPlayerStealCard(PublicPlayerView& player, PublicPlayerView& targetPlayer, PocketType pocketFrom, const PlayingCard* card)
{
    if (mp_parser == 0) return;
    if (card == 0) {
        return;
    }
    GameMessage message;
    message.type = GAMEMESSAGE_PLAYERSTEALCARD;
    message.player = player.id();
    message.targetPlayer = targetPlayer.id();
    
    //else if (card->cardData()){
      message.card = card->cardData();
    //}
    mp_parser->eventGameMessage(message);

    CardMovementData x;
    x.pocketTypeFrom = pocketFrom;
    x.pocketTypeTo   = POCKET_HAND;
    x.playerFrom     = targetPlayer.id();
    x.playerTo       = player.id();
    if (card != 0){
        x.card       = card->cardData();
    }
    mp_parser->eventCardMovement(x);
        getPlayer(playerId())->player()->game()->gameEventManager().onPlayerUpdated(getPlayer(playerId())->player());
        
        targetPlayer.player()->game()->gameEventManager().onPlayerUpdated(targetPlayer.player());

}

void Client::onCancelCard(PocketType pocketFrom, const PlayingCard* card, PublicPlayerView* targetPlayer,
                                PublicPlayerView* p)
{
    if (mp_parser == 0) return;
    if (p != 0 && targetPlayer != 0) {
        GameMessage message;
        message.type = GAMEMESSAGE_PLAYERCANCELCARD;
        message.player = p->id();
        message.targetPlayer = targetPlayer->id();
        message.card = card->cardData();
        mp_parser->eventGameMessage(message);
    }
    CardMovementData x;
    x.pocketTypeFrom = pocketFrom;
    x.pocketTypeTo   = POCKET_GRAVEYARD;
    x.playerFrom     = targetPlayer ? targetPlayer->id() : 0;
    x.playerTo       = 0;
    x.card           = card->cardData();
    mp_parser->eventCardMovement(x);
}

void Client::onCancelCard(PocketType pocketFrom, const PlayingCard* card){
    if (mp_parser == 0) {
        qDebug() << "Parser is NULL";
        return;
        
    }
    
    GameMessage message;
    message.type = GAMEMESSAGE_PLAYERCANCELCARD;
    message.player = 0;
    message.targetPlayer = 0;
    message.card = card->cardData();
    mp_parser->eventGameMessage(message);
    
    CardMovementData x;
    x.pocketTypeFrom = pocketFrom;
    x.pocketTypeTo   = POCKET_GRAVEYARD;
    x.playerFrom     = 0;
    x.playerTo       = 0;
    x.card           = card->cardData();
    mp_parser->eventCardMovement(x);
}

void Client::onPlayerDrawFromBank(PublicPlayerView& player, PlayingCard* card, bool revealCards)
{
    if (mp_parser == 0) return;
    Q_UNUSED(revealCards);
    GameMessage message = GameMessage();
    message.type = GAMEMESSAGE_PLAYERDRAWFROMDECK;
    message.player = player.id();
    message.cards.append(card->cardData()); //segfault
   
    mp_parser->eventGameMessage(message);
    CardMovementData x;
    x.pocketTypeFrom = POCKET_BANK;
    x.pocketTypeTo   = POCKET_HAND;
    x.playerTo       = player.id();
    if (card != 0){
        x.card = card->cardData();
    }
    mp_parser->eventCardMovement(x);
    getPlayer(playerId())->player()->game()->gameEventManager().onPlayerUpdated(getPlayer(playerId())->player());

}

void Client::onPlayerPlayCardOnBank(PublicPlayerView& player, const PlayingCard* card)
{
    if (mp_parser == 0) return;

    GameMessage message;
    message.type = GAMEMESSAGE_PLAYERPLAYCARD;
    message.player = player.id();
    message.card = card->cardData();
    mp_parser->eventGameMessage(message);

    CardMovementData x;
    x.pocketTypeFrom = POCKET_HAND;
    x.pocketTypeTo   = POCKET_BANK;
    x.playerFrom     = player.id();
    x.playerTo       = player.id();
    x.card           = card->cardData();
    mp_parser->eventCardMovement(x);
    getPlayer(playerId())->player()->game()->gameEventManager().onPlayerUpdated(getPlayer(playerId())->player());

}

void Client::onGameContextChange(const GameContextData& gameContextData)
{
    if (mp_parser == 0) return;
    mp_parser->eventGameContextChange(gameContextData);
}

void Client::onLifePointsChange(PublicPlayerView& player, int lifePoints, PublicPlayerView* causedBy)
{
    Q_UNUSED(causedBy);
    if (mp_parser == 0) return;
    mp_parser->eventLifePointsChange(player.id(), lifePoints);
}

void Client::onDeckRegenerate()
{
    if (mp_parser == 0) return;

    GameMessage message;
    message.type = GAMEMESSAGE_DECKREGENERATE;
    mp_parser->eventGameMessage(message);
}

void Client::onPlayerUseAbility(PublicPlayerView&)
{
    ///@todo create new use ability event
}

void Client::onActionRequest(ActionRequestType requestType)
{
    if (mp_parser == 0) return;
    qDebug() << QString("Client (%1): onActionRequest(%2)").arg(m_id).arg(requestType);
    
    if (requestType == REQUEST_DRAW){qDebug() << "REQUEST_DRAW";}
    if (requestType == REQUEST_PLAY){qDebug() << "REQUEST_PLAY";}
    if (requestType == REQUEST_RESPOND){qDebug() << "REQUEST_RESPOND";}
    if (requestType == REQUEST_DISCARD){qDebug() << "REQUEST_DISCARD";}
            
}


PublicPlayerView* Client::getPlayer(int playerId)
{
    PublicPlayerView* res = mp_publicGameView->publicPlayerView(playerId);
    if (res == 0)
        qDebug(qPrintable(QString("[CLIENT]   Target player '%1' not exist!").arg(playerId)));
    return res;
}

PlayingCard* Client::getCard(int cardId)
{
    PlayingCard* card = mp_playerCtrl->card(cardId);
    if (card == 0) {
        qDebug(qPrintable(QString("[CLIENT]   Target card '%1' not exist!").arg(cardId)));
    }
    if ((card->owner() != getPlayer(playerId())->player())){
        qDebug(qPrintable(QString("[CLIENT]   Target card '%1' isn't yours!").arg(cardId)));
        //return 0;
    }
    return card;
}

QList<PlayingCard*> Client::getCards(QList<int> cardIds)
{
    QList<PlayingCard*> res;
    foreach(int cardId, cardIds) {
        PlayingCard* card = getCard(cardId);
        if ((card != 0) /*&& (card->owner() == getPlayer(playerId())->player())*/)
            res.append(card);
    }
    return res;
}



bool Client::isInGame() const
{
    return (mp_playerCtrl != 0);
}

