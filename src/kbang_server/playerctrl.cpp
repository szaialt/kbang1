#include "gameserver.h"
#include "game.h"
#include "gamecycle.h"
#include "player.h"
#include "playerctrl.h"
#include "gameeventlistener.h"
#include "gametable.h"
#include "playingcard.h"
#include "characterbase.h"
#include "gameinfo.h"
#include "reactionhandler.h"

//This needs a setter window to customize the game
//e. g. how many characters must be given to a player to chooese his or her charachter(s).

PlayerCtrl::PlayerCtrl(Player* player):
        QObject(player),
        mp_player(player),
        m_charmed(false)/*,
        charactersToDeal(1)*/
{

}

void PlayerCtrl::disconnect()
{
    mp_player->game()->removePlayer(mp_player);
}

void PlayerCtrl::startGame()
{
    mp_player->game()->startGame(mp_player, charactersToDeal);
}

void PlayerCtrl::draw()
{   
    mp_player->game()->gameCycle().draw(mp_player);    
}

void PlayerCtrl::finishTurn()
{
    mp_player->game()->gameCycle().finishTurn(mp_player);
}

void PlayerCtrl::discardCard(PlayingCard* card)
{
    mp_player->game()->gameCycle().discardCard(mp_player, card);
}

void PlayerCtrl::useAbility()
{
    qDebug() << m_charmed << "1\n";
    if (m_charmed){
        
        throw BadUsageException();
    }
    else {
        mp_player->game()->gameCycle().useAbility(mp_player);
    }
}

void PlayerCtrl::useAbility(const PublicPlayerView* targetPlayer)
{
    qDebug() << m_charmed << "2\n";
    if (m_charmed){
        
        throw BadUsageException();
    }
    else {
        mp_player->game()->gameCycle().useAbility(mp_player, Player::player(targetPlayer));
    }
}

void PlayerCtrl::useAbility(QList<PlayingCard*> cards)
{
    qDebug() << m_charmed << "3\n";
    if (m_charmed){
        throw BadUsageException();
    }
    else {
        mp_player->game()->gameCycle().useAbility(mp_player, cards);
    }
}

void PlayerCtrl::useAbility(QList<PlayingCard*> cards, const PublicPlayerView* targetPlayer)
{
    qDebug() << m_charmed << "4\n";
    if (m_charmed){
        throw BadUsageException();
    }
    else {
        mp_player->game()->gameCycle().useAbility(mp_player, cards, Player::player(targetPlayer));
    }
}


void PlayerCtrl::playCard(PlayingCard* card)
{
    qDebug() << m_charmed << "5\n";
        mp_player->game()->gameCycle().playCard(mp_player, card);
}

void PlayerCtrl::playCard(PlayingCard* card, PublicPlayerView* targetPlayer)
{
    qDebug() << m_charmed << "6\n";
        mp_player->game()->gameCycle().playCard(mp_player,
                                            card,
                                            Player::player(targetPlayer));
}

void PlayerCtrl::playCard(PlayingCard* card, PlayingCard* targetCard)
{
    qDebug() << m_charmed << "7\n";
        mp_player->game()->gameCycle().playCard(mp_player,
                                            card,
                                            targetCard);
    
}

void PlayerCtrl::playCard(PlayingCard* card, PlayingCard* targetCard,  PublicPlayerView* targetPlayer)
{
    qDebug() << m_charmed << "8\n";
    
    mp_player->game()->gameCycle().playCard(mp_player,
                                            card,
                                            targetCard,
                                            Player::player(targetPlayer));
}

void PlayerCtrl::playCard(PlayingCard* card, QList<PlayingCard*> targetCards)
{
    qDebug() << m_charmed << "9\n";
        mp_player->game()->gameCycle().playCard(mp_player,
                                            card,
                                            targetCards);
}

void PlayerCtrl::playCard(PlayingCard* card, QList<PublicPlayerView*> players){
    qDebug() << m_charmed << "10\n";
        mp_player->game()->gameCycle().playCard(mp_player,
                                            card,
                                            players);
}

void PlayerCtrl::pass()
{
    mp_player->game()->gameCycle().pass(mp_player);
}

PlayerRole PlayerCtrl::role() {
    return mp_player->role();
}

CharacterType PlayerCtrl::character() {
  return mp_player->character()->characterType();
}

void PlayerCtrl::sendChatMessage(const QString& message)
{
    mp_player->game()->sendChatMessage(mp_player, message);
}


PlayingCard* PlayerCtrl::card(int cardId) const
{
        qDebug() << "owner:" << mp_player->name();

    PlayingCard* c = mp_player->game()->gameTable().card(cardId);
    if (c == 0) {
        qDebug() << "Not found.";
        return c;
    }
    qDebug() << "card:" << playingCardTypeToString(c->type());
    qDebug() << "pocket:" << pocketTypeToString(c->pocket());
    if (c->pocket() == POCKET_TABLE)
        return c;

    if (c->pocket() == POCKET_SELECTION &&
        (c->owner() == 0 || c->owner() == mp_player))
        return c;

    if (c->pocket() == POCKET_HAND)
        return c;
    return 0;
}

const PublicGameView& PlayerCtrl::publicGameView() const
{
    return mp_player->game()->publicGameView();
}

PublicPlayerView& PlayerCtrl::publicPlayerView(int playerId) const
{
    if (playerId == 0)
        return mp_player->publicView();
    Player* player = mp_player->game()->player(playerId);
    if (player != 0) return player->publicView();
    throw BadPlayerException(playerId);
}

const PrivatePlayerView& PlayerCtrl::privatePlayerView() const
{
    return mp_player->privateView();
}




void PlayerCtrl::createGame(const CreateGameData& game, const CreatePlayerData& player, GameEventListener* handler)
{
    Game* newGame = GameServer::instance().createGame(game);
    Q_ASSERT(newGame != 0);
    
    Player* newPlayer = newGame->createPlayer(player, handler);
    Q_ASSERT(newPlayer != 0);
}

void PlayerCtrl::joinGame(int gameId, const QString& gamePassword,
                          const CreatePlayerData& player, GameEventListener* handler)
{
    Game* game = GameServer::instance().game(gameId);
    if (game == 0)
        throw BadGameException();

//     if (!game->gameInfo().comparePlayerPassword(gamePassword))
//         throw BadGamePasswordException();

    Player* newPlayer = game->createPlayer(player, handler);
    Q_ASSERT(newPlayer != 0);
}


void PlayerCtrl::replacePlayer(int gameId, int playerId, const QString& gamePassword,
                                const CreatePlayerData& createPlayerData,
                                GameEventListener* gameEventListener)
{
    Game* game = GameServer::instance().game(gameId);
    if (game == 0)
        throw BadGameException();

//     if (!game->gameInfo().comparePlayerPassword(gamePassword))
//         throw BadGamePasswordException();

    Player* player = game->player(playerId);
    if (player == 0)
        throw BadTargetPlayerException();

    game->replacePlayer(player, createPlayerData, gameEventListener);
}


ServerInfoData PlayerCtrl::serverInfo()
{
    return GameServer::instance().serverInfo();
}

QList<const PublicGameView*> PlayerCtrl::publicGameList()
{
    QList<const PublicGameView*> result;
    foreach(Game* game,GameServer::instance().gameList()) {
        result.append(&game->publicGameView());
    }
    return result;
}

const PublicGameView& PlayerCtrl::publicGameView(int gameId)
{
    Game* game = GameServer::instance().game(gameId);
    if (game == 0)
        throw BadGameException();
    return game->publicGameView();
}

PlayingCard* PlayerCtrl::getRandomCardFromHand(){
    return mp_player->getRandomCardFromHand();
}

Player* PlayerCtrl::theSheriff(){
    return mp_player->game()->gameCycle().theSheriff();
}

bool PlayerCtrl::isCharmed(){
    return m_charmed;
}

void PlayerCtrl::charm(){
    m_charmed = true;
}

void PlayerCtrl::unCharm(){
    m_charmed = false;
}
