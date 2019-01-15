#include "lifepointschangeevent.h"
#include "game.h"
#include "characterwidget.h"

using namespace client;

LifePointsChangeEvent::LifePointsChangeEvent(Game* game, int playerId, int lifePoints):
        GameEvent(game),
        m_playerId(playerId),
        m_lifePoints(lifePoints)

{ 
}

LifePointsChangeEvent::~LifePointsChangeEvent()
{
}

void LifePointsChangeEvent::run()
{
    if (m_lifePoints < 0)
        m_lifePoints = 0;

     if (m_lifePoints > 10)
         m_lifePoints = 10;

    connect(mp_game->playerWidget(m_playerId)->characterWidget(), SIGNAL(animationFinished()),
            this,                                                  SLOT(finish()));
    mp_game->playerWidget(m_playerId)->characterWidget()->setLifePoints(m_lifePoints);
    mp_game->playerWidget(m_playerId)->update();
}

void LifePointsChangeEvent::stop()
{
}
