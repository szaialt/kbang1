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
#ifndef LOGWIDGET_H
#define LOGWIDGET_H

#include <QWidget>
#include "ui_logwidget.h"

namespace client {

/**
 * @author MacJariel <echo "badmailet@gbalt.dob" | tr "edibmlt" "ecrmjil">
 */
class LogWidget : public QWidget, public Ui::LogWidget
{
Q_OBJECT
public:
    LogWidget(QWidget *parent = 0);
    ~LogWidget();

protected:
    virtual void paintEvent(QPaintEvent* event);

public slots:
    void appendLogMessage(QString message);





    void appendIncomingData(const QByteArray& data);
    void appendOutgoingData(const QByteArray& data);



private:
    int m_dataType;
};
}
#endif
