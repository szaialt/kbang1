/***************************************************************************
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
#ifndef CLIENTCARDLISTWIDGET_H
#define CLIENTCARDLISTWIDGET_H

#include <cardpocket.h>
#include <cardwidget.h>

#include <QList>

namespace client {

/**
 * @author MacJariel <MacJariel@gmail.com>
 */
class CardListWidget: public CardPocket
{
Q_OBJECT
public:
    CardListWidget(QWidget *parent);
    void setCardSize(const CardWidget::Size& cardSize);
    virtual ~CardListWidget();

    virtual void push(CardWidget* card);
    virtual QPoint newCardPosition() const;

    virtual CardWidget* take(int cardId);
    virtual CardWidget* pop();

    virtual void showEvent(QShowEvent*);
    virtual void paintEvent(QPaintEvent*);

    void setHasBox(bool hasBox);

    void clear();

protected:
    QList<CardWidget*> m_cards;

private:
    void reorder();
    int cardX(int i, bool newCard = 0) const;

private:
    CardWidget::Size m_cardSize;
    bool             m_hasBox;
    bool             m_revealed;
    int              m_moveFactor;
    int              m_hPadding, m_vPadding;
};

}

#endif
