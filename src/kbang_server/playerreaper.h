#ifndef PLAYERREAPER_H
#define PLAYERREAPER_H
#include "characterbase.h"

class Game;
class Player;


class PlayerReaper
{
public:
    PlayerReaper(Game* game = 0);
    //If there are more vulture characters, it deals cards of corpse randomly
    virtual void cleanUpCards(Player* corpse);
    virtual ~PlayerReaper() {}
    /**
    * This method is called (by Game) when a vulture character is
    * put in the game.
    */
    virtual void registerVulture(CharacterBase* vulture);
    
    /**
    * This method is called (by Game) when vulture character is
    * removed from the game.
    */
    virtual void unregisterVulture(CharacterBase* vulture);
private:
    Game* mp_game;
    QList<CharacterBase*> m_vultures;
    QList<PlayingCard*> m_selection;
    int vultureIndex;

};

#endif // PLAYERREAPER_H
