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
#include "characterdjango.h"
#include "charactervienna.h"
#include "characterernestsaliven.h"
#include "characterernestsaliven2.h"
#include "charactercardkeeper.h"
#include "charactertomyleeghost.h"
#include "charactergordonchristensen.h"
#include "charactercaptwcaroll.h"
#include "characterelfantasma.h"
#include "charactercheckingblack.h"
#include "cardweakness.h"
#include "carddrawcards.h"

#include <QDebug>

GameCycle::GameCycle(Game* game): 
        QObject(game),
        mp_game(game),
        m_state(GAMEPLAYSTATE_INVALID),
        mp_currentPlayer(0),
        mp_requestedPlayer(0),
        m_isCardEffect(0),
        m_needsFinishTurn(false),
        m_duplicateTurn(false),
        m_deflectionFlag(false),
        m_draw(true)
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
    resetAbility(player);
//     if (player->characterType() == CHARACTER_EL_FANTASMA){
//         player->setAlive(true);
//         player->character()->useAbility();
//     }
    Player::CardList table = player->table();
    foreach(PlayingCard* c, table){
        c->setAct(true); 
        if (c->type() == CARD_PERSUASION){
            CardPersuasion* card = qobject_cast<CardPersuasion*>(c);
            card->resetTimes();
        }
        if (c->type() == CARD_GOLD_WATCH){
            CardDrawCards* card = qobject_cast<CardDrawCards*>(c);
            card->reset();
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
    if (m_draw){
        if (player->isCharmed()){
            player->game()->gameTable().playerDrawFromDeck(player, 2, 0);
        }
        else {
            player->character()->draw(specialDraw);
        }
    }
    else {
        m_draw = true;
    }
    m_contextDirty = 1;
    sendRequest();
}

void GameCycle::noDraw(){
    m_draw = false;
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
         if (c->color() != COLOR_BROWN){
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
         if (c->color() == COLOR_POSITIVE_GREY){
             if (!c->isAct()){
                 c->setAct(true); 
             }
             else {
                 mp_game->gameTable().playerDiscardCard(c);
            }
         }
         if (c->type() == CARD_WEAKNESS){
             CardWeakness* card =  qobject_cast<CardWeakness*>(c);
             card->vulnerate();
         }
         if (c->color() == COLOR_NEGATIVE_GREY){
             mp_game->gameTable().playerDiscardCard(c);
        }
         if (c->type() == CARD_INFLAMMATORY_BOTTLE){
             player->modifyLifePoints(-1, 0);
             if (player->lifePoints() <= 0){
                 mp_game->buryPlayer(player, 0);
            }
         }/*
         if (player->lifePoints() <= 0){
            mp_game->buryPlayer(player, 0);
         }*/
         
     }
     player->unCharm();
     if (!(player->isCharmed()) && (player->characterType() == CHARACTER_TOMY_LEE_GHOST)){
            CharacterTomyLeeGhost* ghost =  qobject_cast<CharacterTomyLeeGhost*>(player->character());
            ghost->decrementRounds();
            ghost->setDead();
        }
    player->setHexxZombie(false);
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
        Player::CardList table = player->table();
        foreach(PlayingCard* c, table){
            if (c->type() == CARD_WEAKNESS){
                CardWeakness* card =  qobject_cast<CardWeakness*>(c);
                card->increasePlayedCards();
            }
        }
        if (player->isCharmed()){
            card->play();
        }
        else{
            player->character()->playCard(card);
        }
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

    if ((!targetPlayer->isAlive()) && (card->type() != CARD_DIRTY_JOB)){
        throw BadTargetPlayerException();
    }

    if (isResponse()){
        throw BadGameStateException();
    }
    Player::CardList table = player->table();
    foreach(PlayingCard* c, table){
        if (c->type() == CARD_WEAKNESS){
            CardWeakness* card =  qobject_cast<CardWeakness*>(c);
            card->increasePlayedCards();
        }
    }
    if (player->isCharmed()){
        card->play(targetPlayer);
    }
    else {
        player->character()->playCard(card, targetPlayer);
    }
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
    Player::CardList table = player->table();
    foreach(PlayingCard* c, table){
        if (c->type() == CARD_WEAKNESS){
            CardWeakness* card =  qobject_cast<CardWeakness*>(c);
            card->increasePlayedCards();
        }
    }
    if (player->isCharmed()){
        card->play(targetCard);
    }
    else {
        player->character()->playCard(card, targetCard);
    }
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

    if ((!targetPlayer->isAlive())){
        throw BadTargetPlayerException();
    }

    if (isResponse()){
        throw BadGameStateException();
    }
    Player::CardList table = player->table();
    foreach(PlayingCard* c, table){
        if (c->type() == CARD_WEAKNESS){
            CardWeakness* card =  qobject_cast<CardWeakness*>(c);
            card->increasePlayedCards();
        }
    }
    if (player->isCharmed()){
        card->play(targetCard, targetPlayer);
    }
    else {
        player->character()->playCard(card, targetCard, targetPlayer);
    }
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
    Player::CardList table = player->table();
    foreach(PlayingCard* c, table){
        if (c->type() == CARD_WEAKNESS){
            CardWeakness* card =  qobject_cast<CardWeakness*>(c);
            card->increasePlayedCards();
        }
    }
    if (player->isCharmed()){
        card->play(targetCards);
    }
    else {
        player->character()->playCard(card, targetCards);
    }
    sendRequest();
}

void GameCycle::playCard(Player* player, PlayingCard* card, QList<PublicPlayerView*> targetPlayers)
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
    Player::CardList table = player->table();
    foreach(PlayingCard* c, table){
        if (c->type() == CARD_WEAKNESS){
            CardWeakness* card =  qobject_cast<CardWeakness*>(c);
            card->increasePlayedCards();
        }
    }
    if (player->isCharmed()){
        QList<Player*> players = QList<Player*>();
        foreach (PublicPlayerView* targetPlayer, targetPlayers){
            players.push_back(targetPlayer->player());
        }
        card->play(players);
    }
    else {
        player->character()->playCard(card, targetPlayers);
    }
    sendRequest();
}


void GameCycle::pass(Player* player)
{
    m_contextDirty = 0; 
//     if (reactionHandler()->reactionType() == REACTION_BANDIDOS){
//         mp_requestedPlayer = player;
//     }
    if ((!m_deflectionFlag) && (player != mp_requestedPlayer)){
        qDebug() << "void GameCycle::pass(Player* player) ";
        if ((player != 0) && (mp_requestedPlayer != 0)){
            qDebug() << player->name() << " would pass.";
            qDebug() << "Could pass " << mp_requestedPlayer->name();
        }
        throw BadPlayerException(mp_currentPlayer->id());
    }
    if (m_state != GAMEPLAYSTATE_RESPONSE){
        throw BadGameStateException();
    }
    try {
        player->character()->respondPass(m_reactionHandlers.head());
        m_deflectionFlag = false;
    }
    catch (TooManyCardsInHandException ex){
        if (m_needsFinishTurn) {
            qDebug() << "void GameCycle::pass(Player* player) ";
            qDebug() << "TooManyCardsInHandException caught because of CARD_DEAD_RINGER";
        }
        else throw ex;
    }
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

void GameCycle::resetAbility(Player* player){
    if (player->characterType() == CHARACTER_DJANGO){
        CharacterDjango* dj =  qobject_cast<CharacterDjango*>(player->character());
        dj->resetAbility();
    }
    else if (player->characterType() == CHARACTER_VIENNA){
        CharacterVienna* vienna =  qobject_cast<CharacterVienna*>(player->character());
        vienna->resetAbility();
    }
    else if (player->characterType() == CHARACTER_ERNEST_SALIVEN){
        CharacterErnestSaliven* ernest =  qobject_cast<CharacterErnestSaliven*>(player->character());
        ernest->resetAbility();
    }
    else if (player->characterType() == CHARACTER_ERNEST_SALIVEN2){
        CharacterErnestSaliven2* ernest =  qobject_cast<CharacterErnestSaliven2*>(player->character());
        ernest->resetAbility();
    }
    else if (player->characterType() == CHARACTER_GORDON_CHRISTENSEN){
        CharacterGordonChristensen* christ =  qobject_cast<CharacterGordonChristensen*>(player->character());
        christ->resetAbility();
    }
    else if (player->characterType() == CHARACTER_CAPT_W_CAROLL){
        CharacterGordonChristensen* christ =  qobject_cast<CharacterGordonChristensen*>(player->character());
        christ->resetAbility();
    }
    else if (player->characterType() == CHARACTER_WILLIAM_HARMAN){
        CharacterCheckingBlack* black =  qobject_cast<CharacterCheckingBlack*>(player->character());
        black->resetAbility();
    }
    else if (player->characterType() == CHARACTER_CLOCKWORK){
        CharacterCheckingBlack* black =  qobject_cast<CharacterCheckingBlack*>(player->character());
        black->resetAbility();
    }
}


int GameCycle::needDiscard(Player* player)
{
    if (!(player->isCharmed()) && (player->characterType() == CHARACTER_TOMY_LEE_GHOST)){
        CharacterTomyLeeGhost* ghost =  qobject_cast<CharacterTomyLeeGhost*>(player->character());
        if (ghost->isAtFirstDead())
            if (player->lifePoints() < 0){
                player->modifyLifePoints(-(player->lifePoints()), 0);
        }
    }
    int limit = player->lifePoints();
    int handSize = player->handSize();
    int muleLimit = 6;
    int muleSize = 4;
    int pocketSize = 2;
    if (player->characterType() == CHARACTER_BILLY_LONGLIFE){
        CharacterCardKeeper* billy =  qobject_cast<CharacterCardKeeper*>(player->character());
        limit = billy->cardKeeping();
    }
    foreach (PlayingCard* card, player->table()){
        if (card->type() == CARD_PACK_MULE){
            limit = muleLimit;
        }
        if (card->type() == CARD_PACKING_MULE){
            limit = limit + muleSize;
        }
        if (card->type() == CARD_COWBOY_POCKET){
            limit = limit + pocketSize;
        }
    }
    if (limit > handSize) {
        return 0;
    }
    else {
        qDebug() << "Needs discard " << handSize - limit << " cards.";
        return handSize - limit;
    }
}

void GameCycle::announceContextChange()
{
    mp_game->gameEventManager().onGameContextChange(gameContextData());
}

void GameCycle::deflectionPlayed(){
    m_deflectionFlag = true;
}
