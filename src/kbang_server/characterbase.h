#ifndef CHARACTERBASE_H
#define CHARACTERBASE_H

#include <QObject>
#include <QList>
#include "parser/parserstructs.h"
#include "publicplayerview.h"

class Player;
class PlayingCard;
class ReactionHandler;
class GameTable;
class GameCycle;
class CheckDeckResultHandler;

class CharacterBase : public QObject
{
//Q_OBJECT;
public:
    CharacterBase(QObject *parent, CharacterType);

    inline CharacterType characterType() const { return m_characterType; }
    
    
    virtual int maxLifePoints() const;

    virtual void draw(bool specialDraw);

    virtual void playCard(PlayingCard* card);
    virtual void playCard(PlayingCard* card, Player* targetPlayer);
    virtual void playCard(PlayingCard* card, PlayingCard* targetCard);
    virtual void playCard(PlayingCard* card, PlayingCard* targetCard, Player* targetPlayer);
    virtual void playCard(PlayingCard* card, QList<PlayingCard*> targetCards);
    virtual void playCard(PlayingCard* card, QList<PublicPlayerView*> targetPlayers);
    
    virtual void respondPass(ReactionHandler*);
    virtual void respondCard(ReactionHandler*, PlayingCard* targetCard);
    virtual void respondCard(ReactionHandler*, QList<PlayingCard*> targetCards);
    
    virtual void useAbility();
    virtual void useAbility(Player* targetPlayer);
    virtual void useAbility(QList<PlayingCard*> cards);
    virtual void useAbility(QList<PlayingCard*> cards, Player* targetPlayer);

    virtual void setPlayer(Player* player);
    virtual Player* player(){return mp_player;}
    virtual void playerDied();

    virtual void checkDeck(PlayingCard* causedBy, bool (*checkFunc)(PlayingCard*), CheckDeckResultHandler*);
    //virtual void resetAbility();

protected:
    void setCharacterType(CharacterType type);
    void notifyAbilityUse();

    GameTable& gameTable();
    GameCycle& gameCycle();

    CharacterType m_characterType;
    Player*       mp_player;

};

#endif // CHARACTERBASE_H
