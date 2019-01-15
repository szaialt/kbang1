#include "cardwidgetsizemanager.h"

using namespace client;

qreal CardWidgetSizeManager::sm_cardRatio = 20 / 31;
//qreal CardWidgetSizeManager::sm_lifePointCardRatio[] = {0, 19/150, 31/150, 44/150, 57/150, 68/150, 94/150, 106/150, 119/150, 132/150, 143/150, 150/150};
int CardWidgetSizeManager::sm_initialHeight = 75; 

CardWidgetSizeManager::CardWidgetSizeManager(QObject* parent):
        QObject(parent)
{
    m_normalSize = QSize(width(sm_initialHeight), sm_initialHeight);
    m_zoomSize = QSize(200, 310);
}

QSize CardWidgetSizeManager::initialSize()
{
    return QSize(width(sm_initialHeight), sm_initialHeight);
}

int CardWidgetSizeManager::width(int height)
{
    return (int)(height * sm_cardRatio);
}
