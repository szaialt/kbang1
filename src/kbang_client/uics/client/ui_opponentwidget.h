/********************************************************************************
** Form generated from reading UI file 'opponentwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPPONENTWIDGET_H
#define UI_OPPONENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "cardlistwidget.h"
#include "characterwidget.h"

QT_BEGIN_NAMESPACE

class Ui_OpponentWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *mp_labelAvatar;
    QSpacerItem *verticalSpacer;
    client::CharacterWidget *mp_characterWidget;
    QVBoxLayout *verticalLayout;
    QLabel *mp_labelPlayerName;
    QSpacerItem *verticalSpacer_2;
    client::CardListWidget *mp_hand;
    client::CardListWidget *mp_table;

    void setupUi(QWidget *OpponentWidget)
    {
        if (OpponentWidget->objectName().isEmpty())
            OpponentWidget->setObjectName(QStringLiteral("OpponentWidget"));
        OpponentWidget->resize(211, 192);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OpponentWidget->sizePolicy().hasHeightForWidth());
        OpponentWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(OpponentWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(4, 4, 4, 4);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
#ifndef Q_OS_MAC
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
#endif
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        mp_labelAvatar = new QLabel(OpponentWidget);
        mp_labelAvatar->setObjectName(QStringLiteral("mp_labelAvatar"));
        sizePolicy.setHeightForWidth(mp_labelAvatar->sizePolicy().hasHeightForWidth());
        mp_labelAvatar->setSizePolicy(sizePolicy);
        mp_labelAvatar->setMinimumSize(QSize(48, 48));
        mp_labelAvatar->setMaximumSize(QSize(48, 48));
        mp_labelAvatar->setStyleSheet(QLatin1String("background-color: rgba(0, 0, 0, 64);\n"
"color: white;\n"
"font: oblique 7pt \"DejaVu Sans\";"));
        mp_labelAvatar->setTextFormat(Qt::AutoText);
        mp_labelAvatar->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(mp_labelAvatar);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        mp_characterWidget = new client::CharacterWidget(OpponentWidget);
        mp_characterWidget->setObjectName(QStringLiteral("mp_characterWidget"));

        verticalLayout_2->addWidget(mp_characterWidget);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        mp_labelPlayerName = new QLabel(OpponentWidget);
        mp_labelPlayerName->setObjectName(QStringLiteral("mp_labelPlayerName"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mp_labelPlayerName->sizePolicy().hasHeightForWidth());
        mp_labelPlayerName->setSizePolicy(sizePolicy1);
        mp_labelPlayerName->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(15);
        mp_labelPlayerName->setFont(font);
        mp_labelPlayerName->setStyleSheet(QStringLiteral("color: white;"));
        mp_labelPlayerName->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(mp_labelPlayerName);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        mp_hand = new client::CardListWidget(OpponentWidget);
        mp_hand->setObjectName(QStringLiteral("mp_hand"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mp_hand->sizePolicy().hasHeightForWidth());
        mp_hand->setSizePolicy(sizePolicy2);
        mp_hand->setMinimumSize(QSize(0, 75));

        verticalLayout->addWidget(mp_hand);

        mp_table = new client::CardListWidget(OpponentWidget);
        mp_table->setObjectName(QStringLiteral("mp_table"));
        sizePolicy2.setHeightForWidth(mp_table->sizePolicy().hasHeightForWidth());
        mp_table->setSizePolicy(sizePolicy2);
        mp_table->setMinimumSize(QSize(0, 75));

        verticalLayout->addWidget(mp_table);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(OpponentWidget);

        QMetaObject::connectSlotsByName(OpponentWidget);
    } // setupUi

    void retranslateUi(QWidget *OpponentWidget)
    {
        OpponentWidget->setWindowTitle(QApplication::translate("OpponentWidget", "Opponent Widget", nullptr));
        mp_labelAvatar->setText(QString());
        mp_labelPlayerName->setText(QApplication::translate("OpponentWidget", "{PLAYERNAME}", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpponentWidget: public Ui_OpponentWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPPONENTWIDGET_H
