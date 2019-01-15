#include "gamecycle.h"
#include "gametable.h"
#include "gameexceptions.h"
#include "game.h"
#include "player.h"
#include "gameeventlistener.h"
#include "gameeventmanager.h"
#include "reactioncard.h"
#include "characterbase.h"
#include "cardpersuasion.h"

#include <QDebug>

GameCycle::GameCycle(Game* game): 
        QObject(game),
        mp_game(game),
        m_state(GAMEPLAYSTATE_INVALID),
        mp_currentPlayer(0),
        mp_requestedPlayer(0),
        m_isCardEffect(0),
        m_needsFinishTurn(false),
        m_duplicateTurn(false)
{
}

GameCycle::~GameCycle()
{
}

void GameCycle::assertDraw() const
{
    if (!isDraw())
        throw BadGamePlayStateException(m_state, GAMEPLAYSTATE_DRAW);
}

void GameCycle::assertTurn() const
{
    if (!isTurn())
        throw BadGamePlayStateException(m_state, GAMEPLAYSTATE_TURN);
}

void GameCycle::assertResponse() const
{
    if (!isResponse())
        throw BadGamePlayStateException(m_state, GAMEPLAYSTATE_RESPONSE);
}

 void GameCycle::assertDiscard() const
 {
     if (!isDiscard())
         throw BadGamePlayStateException(m_state, GAMEPLAYSTATE_DISCARD);
 }


GameContextData GameCycle::gameContextData() const
{
    GameContextData res;
    if (currentPlayer() == NULL ) {
        res.currentPlayerId = 0;
    }
    else { 
        res.currentPlayerId   = currentPlayer()->id(); 
    }
    if (requestedPlayer() == NULL ) {
        res.requestedPlayerId = 0;
    }
    else { 
        res.requestedPlayerId = requestedPlayer()->id(); 
    }
    res.turnNumber        = turnNumber();
    res.gamePlayState     = gamePlayState();
    qDebug() << "Gamecycle: gamePlayState is " << gamePlayStateToString(gamePlayState());
    
    if (gamePlayState() == GAMEPLAYSTATE_RESPONSE) {
        //don't knows the new reactionTypes!
        res.reactionType = reactionHandler()->reactionType();
        qDebug() << "Gamecycle: reactionType is " << reactionTypeToString(reactionHandler()->reactionType()); 
        Player* causedBy = reactionHandler()->causedBy();
        res.causedBy = causedBy ? causedBy->id() : 0;

    } else {
        res.reactionType = REACTION_NONE;
        res.causedBy     = 0;
    }
    return res;
}

Player* GameCycle::theSheriff(){
    Player* player;
    foreach (player, mp_game->playerList())
        if (player->role() == ROLE_SHERIFF)
            break;
    Q_ASSERT(player->role() == ROLE_SHERIFF);
    return player;
}

void GameCycle::start()
{
    m_contextDirty = 0;
    Player* player = theSheriff();
    m_turnNum = 0;
    startTurn(player);
    sendRequest();
}

void GameCycle::startTurn(Player* player)
{
    m_contextDirty = 1;
    Player::CardList table = player->table();
    foreach(PlayingCard* c, table){
         if (c->color() == COLOR_GREEN){
             c->setAct(true);             
        }
        if (c->type() == CARD_PERSUASION){
            CardPersuasion* card = qobject_cast<CardPersuasion*>(c);
            card->resetTimes();
        }
     }
    if (player->role() == ROLE_SHERIFF)
        m_turnNum++;
    mp_currentPlayer = mp_requestedPlayer = player;
    m_state = GAMEPLAYSTATE_DRAW;
    mp_currentPlayer->onTurnStart();
    m_drawCardCount = 0;
    m_drawCardMax = 2;
}

void GameCycle::draw(Player* player, bool specialDraw)
{
    m_contextDirty = 0;
    checkPlayerAndState(player, GAMEPLAYSTATE_DRAW);
    player->predrawCheck(0);
    m_state = GAMEPLAYSTATE_TURN;
    player->character()->draw(specialDraw);
    m_contextDirty = 1;
    sendRequest();
}


void GameCycle::skipPlayersTurn()
{
    m_contextDirty = 0;
    Player* player = mp_currentPlayer;
    if (player->unlimitedBangs() < 0){
        player->setUnlimitedBangs(-(player->unlimitedBangs()));
    }
    Player::CardList table = player->table();
     foreach(PlayingCard* c, table){
         if (c->color() == COLOR_GREEN){
             c->setAct(true);             
        }
     }
    startTurn(mp_game->nextPlayer(mp_currentPlayer));
}

void GameCycle::finishTurn(Player* player)
{
    m_contextDirty = 0;
    if (player != mp_requestedPlayer){
        throw BadPlayerException(mp_currentPlayer->id());
    }
    if ((m_state != GAMEPLAYSTATE_TURN) && (m_state != GAMEPLAYSTATE_DISCARD)){
        throw BadGameStateException();
    }
    if (needDiscard(player)){
        throw TooManyCardsInHandException();
    }
    if (player->unlimitedBangs() < 0){
        player->setUnlimitedBangs(-(player->unlimitedBangs()));
    }
    Player::CardList table = player->table();
     foreach(PlayingCard* c, table){
         if (c->color() == COLOR_GREEN){
             c->setAct(true);             
        }
     }
    if (m_duplicateTurn){
        m_duplicateTurn = false;
        startTurn(mp_currentPlayer);
    }
    else {
        startTurn(mp_game->nextPlayer(mp_currentPlayer));
    }
    sendRequest();
}

void GameCycle::discardCard(Player* player, PlayingCard* card)
{
    m_contextDirty = 0;
    if (player != mp_requestedPlayer)
        throw BadPlayerException(mp_currentPlayer->id());

    if (m_state != GAMEPLAYSTATE_TURN && m_state != GAMEPLAYSTATE_DISCARD)
        throw BadGameStateException();

    if (needDiscard(player) == 0)
        throw BadGameStateException();

    if (card->owner() != mp_requestedPlayer || card->pocket() != POCKET_HAND)
        throw BadCardException();

    mp_game->gameTable().playerDiscardCard(card);
    m_state = GAMEPLAYSTATE_DISCARD;
    m_contextDirty = 1;

    if (needDiscard(player) == 0)
        startTurn(mp_game->nextPlayer(mp_currentPlayer));
    sendRequest();
}

void GameCycle::playCard(Player* player, PlayingCard* card)
{
    m_contextDirty = 0;
    if (player != mp_requestedPlayer){
        throw BadPlayerException(mp_currentPlayer->id());
    }

    if (card->owner() != 0 && card->owner() != player) {
        throw BadCardException();
    }

    if (isResponse()) {
        player->character()->respondCard(m_reactionHandlers.head(), card);
    } else {
        if (card->owner() == 0) {
            qDebug() << "Cannot play card owned by nobody.";
            throw BadCardException();
        }
        player->character()->playCard(card);
    }
    sendRequest();
}

void GameCycle::playCard(Player* player, PlayingCard* card, Player* targetPlayer)
{
    m_contextDirty = 0;
    if (player != mp_requestedPlayer){
        throw BadPlayerException(mp_currentPlayer->id());
    }

    if (card->owner() !=  0 && card->owner() != player) {
        throw BadCardException();
    }

    if (!targetPlayer->isAlive()){
        throw BadTargetPlayerException();
    }

    if (isResponse()){
        throw BadGameStateException();
    }
    player->character()->playCard(card, targetPlayer);
    sendRequest();
}

void GameCycle::playCard(Player* player, PlayingCard* card, PlayingCard* targetCard)
{
    m_contextDirty = 0;
    if (player != mp_requestedPlayer){
        throw BadPlayerException(mp_currentPlayer->id());
    }
    if (card->owner() !=  0 && card->owner() != player) {
        throw BadCardException();
    }

    if (isResponse()){
        throw BadGameStateException();
    }
    player->character()->playCard(card, targetCard);
    sendRequest();
}

void GameCycle::playCard(Player* player, PlayingCard* card, PlayingCard* targetCard, Player* targetPlayer)
{
    m_contextDirty = 0;
    if (player != mp_requestedPlayer){
        throw BadPlayerException(mp_currentPlayer->id());
    }

    if (card->owner() !=  0 && card->owner() != player) {
        throw BadCardException();
    }

    if (!targetPlayer->isAlive()){
        throw BadTargetPlayerException();
    }

    if (isResponse()){
        throw BadGameStateException();
    }
    player->character()->playCard(card, targetCard, targetPlayer);
    sendRequest();
}

void GameCycle::playCard(Player* player, PlayingCard* card, QList<PlayingCard*> targetCards)
{
    m_contextDirty = 0;
    if (player != mp_requestedPlayer){
        throw BadPlayerException(mp_currentPlayer->id());
    }
    if (card->owner() !=  0 && card->owner() != player) {
        throw BadCardException();
    }

    if (isResponse()){
        throw BadGameStateException();
    }
    player->character()->playCard(card, targetCards);
    sendRequest();
}

void GameCycle::playCard(Player* player, PlayingCard* card, QList<PublicPlayerView*> targetPlayers)
{
    qDebug() << "void GameCycle::playCard(Player* player, PlayingCard* card, QList<PublicPlayerView*> targetPlayers) 1";
    m_contextDirty = 0;
    if (player != mp_requestedPlayer){
        throw BadPlayerException(mp_currentPlayer->id());
    }
    if (card->owner() !=  0 && card->owner() != player) {
        throw BadCardException();
    }
    if (isResponse()){
        throw BadGameStateException();
    }
    player->character()->playCard(card, targetPlayers);
    sendRequest();
}


void GameCycle::pass(Player* player)
{
    m_contextDirty = 0; 
//     if (reactionHandler()->reactionType() == REACTION_BANDIDOS){
//         mp_requestedPlayer = player;
//     }
    if (player != mp_requestedPlayer){
        throw BadPlayerException(mp_currentPlayer->id());
    }
    if (m_state != GAMEPLAYSTATE_RESPONSE){
        throw BadGameStateException();
    }
    player->character()->respondPass(m_reactionHandlers.head());
    sendRequest();
}

void GameCycle::useAbility(Player* player)
{
    m_contextDirty = 0;
    player->character()->useAbility();
    sendRequest();
}

void GameCycle::useAbility(Player* player, Player* targetPlayer)
{
    m_contextDirty = 0;
    player->character()->useAbility(targetPlayer);
    sendRequest();
}

void GameCycle::useAbility(Player* player, QList<PlayingCard*> cards)
{
    m_contextDirty = 0;
    player->character()->useAbility(cards);
    sendRequest();
}

void GameCycle::useAbility(Player* player, QList<PlayingCard*> cards, Player* targetPlayer)
{
    m_contextDirty = 0;
    player->character()->useAbility(cards, targetPlayer);
    sendRequest();
}


void GameCycle::checkDeck(Player* player, PlayingCard* causedBy,
                          bool (*checkFunc)(PlayingCard*), CheckDeckResultHandler* resultHandler)
{
    player->character()->checkDeck(causedBy, checkFunc, resultHandler);
}

void GameCycle::setResponseMode(ReactionHandler* reactionHandler, Player* player, bool skipQueue)
{
    if (m_reactionHandlers.isEmpty()) {
        Q_ASSERT(m_state != GAMEPLAYSTATE_RESPONSE);
        m_lastState = m_state;
    }

    if (skipQueue) {
        m_reactionHandlers.prepend(reactionHandler);
        m_reactionPlayers.prepend(player);
    } else {
        m_reactionHandlers.enqueue(reactionHandler);
        m_reactionPlayers.enqueue(player);
    }
    if (m_reactionHandlers.size() == 1 || skipQueue) {
        mp_requestedPlayer = player;
        m_state = GAMEPLAYSTATE_RESPONSE;
        m_contextDirty = 1;
    }
}

void GameCycle::unsetResponseMode()
{
    Q_ASSERT(m_state == GAMEPLAYSTATE_RESPONSE);
    m_reactionHandlers.dequeue();
    m_reactionPlayers.dequeue();
    if (!m_reactionHandlers.isEmpty()) {
        mp_requestedPlayer = m_reactionPlayers.head();
    } else {
        mp_requestedPlayer = mp_currentPlayer;
        m_state = m_lastState;
    }
    m_contextDirty = 1;
}

void GameCycle::setCardEffect(bool isCardEffect)
{
    bool oldIsCardEffect = m_isCardEffect;
    m_isCardEffect = isCardEffect;
    if (oldIsCardEffect && !m_isCardEffect) {
        emit cardEffectOver();
    }
}

bool GameCycle::isCardEffect() const
{
    return m_isCardEffect;
}

void GameCycle::setNeedsFinishTurn(bool b){
    m_needsFinishTurn = b;
}

void GameCycle::setDuplicateTurn(bool b){
    m_duplicateTurn = b;
}

void GameCycle::sendRequest()
{
    qDebug() << "void GameCycle::sendRequest() 1";
    if (mp_game->isFinished())
        return;
    qDebug() << "void GameCycle::sendRequest() 2";
    if ((m_needsFinishTurn) && (m_state == GAMEPLAYSTATE_TURN)){
        m_state = GAMEPLAYSTATE_DISCARD;
        m_needsFinishTurn = false;
        qDebug() << "void GameCycle::sendRequest(): " << mp_currentPlayer->name();
        try {
            finishTurn(mp_currentPlayer);
        }
        catch(TooManyCardsInHandException ex){
            qDebug() << "void GameCycle::sendRequest(): "; 
            ex.debug();
        }
        catch (GameException& e) {
            e.debug();
        }
    }

    if (!mp_requestedPlayer->isAlive()) {
        qDebug() << "void GameCycle::sendRequest() 3";
        Q_ASSERT(m_state != GAMEPLAYSTATE_RESPONSE);
        startTurn(mp_game->nextPlayer(mp_currentPlayer));
        qDebug() << "void GameCycle::sendRequest() 4";
    }

    qDebug() << "void GameCycle::sendRequest() 5";
    ActionRequestType requestType;
    qDebug() << "void GameCycle::sendRequest() 6";
    switch(m_state) {
        case GAMEPLAYSTATE_DRAW:
            requestType = REQUEST_DRAW;
            break;
        case GAMEPLAYSTATE_TURN:
            requestType = REQUEST_PLAY;
            break;
        case GAMEPLAYSTATE_RESPONSE:
            requestType = REQUEST_RESPOND;
            break;
        case GAMEPLAYSTATE_DISCARD:
            requestType = REQUEST_DISCARD;
            break;
        default:
            NOT_REACHED();
    }
    if (m_contextDirty) {
        announceContextChange();
    }
    GameEventListener* handler = mp_requestedPlayer->gameEventListener();
    if (handler)
        handler->onActionRequest(requestType);
}

void GameCycle::checkPlayerAndState(Player* player, GamePlayState state)
{
    if (player != mp_requestedPlayer)
        throw BadPlayerException(mp_currentPlayer->id());

    if (state != m_state)
        throw BadGameStateException();
}

int GameCycle::needDiscard(Player* player)
{
    int lifePoints = player->lifePoints();
    int handSize = player->handSize();
    if (lifePoints > handSize) {
        return 0;
    }
    else {
        qDebug() << "Needs discard " << handSize - lifePoints << " cards.";
        return handSize - lifePoints;
    }
}

void GameCycle::announceContextChange()
{
    mp_game->gameEventManager().onGameContextChange(gameContextData());
}
