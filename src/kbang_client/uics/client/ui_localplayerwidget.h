/********************************************************************************
** Form generated from reading UI file 'localplayerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCALPLAYERWIDGET_H
#define UI_LOCALPLAYERWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "cardlistwidget.h"
#include "cardwidget.h"
#include "characterwidget.h"

QT_BEGIN_NAMESPACE

class Ui_LocalPlayerWidget
{
public:
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *mp_labelAvatar;
    client::CardWidget *mp_roleCardWidget;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    client::CharacterWidget *mp_characterWidget;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *mp_buttonEndTurn;
    QToolButton *mp_buttonPass;
    QToolButton *mp_buttonDiscard;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *mp_labelPlayerName;
    QSpacerItem *verticalSpacer;
    client::CardListWidget *mp_table;
    client::CardListWidget *mp_hand;

    void setupUi(QWidget *LocalPlayerWidget)
    {
        if (LocalPlayerWidget->objectName().isEmpty())
            LocalPlayerWidget->setObjectName(QStringLiteral("LocalPlayerWidget"));
        LocalPlayerWidget->resize(354, 209);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LocalPlayerWidget->sizePolicy().hasHeightForWidth());
        LocalPlayerWidget->setSizePolicy(sizePolicy);
        LocalPlayerWidget->setMinimumSize(QSize(0, 0));
        LocalPlayerWidget->setBaseSize(QSize(0, 0));
        LocalPlayerWidget->setStyleSheet(QLatin1String("QToolButton {\n"
"	width: 28px;\n"
"	height: 28px;\n"
"	border: 1px solid gray;\n"
"	border-radius: 2px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"\n"
"}\n"
"QToolButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
"QToolButton:checked {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #da5b5e, stop: 1 #f6676a);\n"
"}\n"
"\n"
"QToolButton:default {\n"
"     border-color: navy; \n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(LocalPlayerWidget);
        horizontalLayout_3->setSpacing(4);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(4);
        gridLayout->setVerticalSpacing(0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        mp_labelAvatar = new QLabel(LocalPlayerWidget);
        mp_labelAvatar->setObjectName(QStringLiteral("mp_labelAvatar"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mp_labelAvatar->sizePolicy().hasHeightForWidth());
        mp_labelAvatar->setSizePolicy(sizePolicy1);
        mp_labelAvatar->setMinimumSize(QSize(48, 48));
        mp_labelAvatar->setMaximumSize(QSize(48, 48));
        mp_labelAvatar->setStyleSheet(QLatin1String("background-color: rgba(0, 0, 0, 64);\n"
"color: white;\n"
"font: oblique 7pt \"DejaVu Sans\";"));
        mp_labelAvatar->setTextFormat(Qt::AutoText);
        mp_labelAvatar->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(mp_labelAvatar);

        mp_roleCardWidget = new client::CardWidget(LocalPlayerWidget);
        mp_roleCardWidget->setObjectName(QStringLiteral("mp_roleCardWidget"));

        verticalLayout_3->addWidget(mp_roleCardWidget);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        mp_characterWidget = new client::CharacterWidget(LocalPlayerWidget);
        mp_characterWidget->setObjectName(QStringLiteral("mp_characterWidget"));

        verticalLayout_2->addWidget(mp_characterWidget);

        verticalSpacer_3 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        mp_buttonEndTurn = new QToolButton(LocalPlayerWidget);
        mp_buttonEndTurn->setObjectName(QStringLiteral("mp_buttonEndTurn"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/turn.png"), QSize(), QIcon::Normal, QIcon::Off);
        mp_buttonEndTurn->setIcon(icon);
        mp_buttonEndTurn->setIconSize(QSize(28, 28));

        horizontalLayout_2->addWidget(mp_buttonEndTurn);

        mp_buttonPass = new QToolButton(LocalPlayerWidget);
        mp_buttonPass->setObjectName(QStringLiteral("mp_buttonPass"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/pass.png"), QSize(), QIcon::Normal, QIcon::Off);
        mp_buttonPass->setIcon(icon1);
        mp_buttonPass->setIconSize(QSize(28, 28));

        horizontalLayout_2->addWidget(mp_buttonPass);

        mp_buttonDiscard = new QToolButton(LocalPlayerWidget);
        mp_buttonDiscard->setObjectName(QStringLiteral("mp_buttonDiscard"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/discard.png"), QSize(), QIcon::Normal, QIcon::Off);
        mp_buttonDiscard->setIcon(icon2);
        mp_buttonDiscard->setIconSize(QSize(28, 28));
        mp_buttonDiscard->setCheckable(true);

        horizontalLayout_2->addWidget(mp_buttonDiscard);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 2);


        horizontalLayout_3->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        mp_labelPlayerName = new QLabel(LocalPlayerWidget);
        mp_labelPlayerName->setObjectName(QStringLiteral("mp_labelPlayerName"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mp_labelPlayerName->sizePolicy().hasHeightForWidth());
        mp_labelPlayerName->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(13);
        mp_labelPlayerName->setFont(font);
        mp_labelPlayerName->setStyleSheet(QStringLiteral("color: white;"));
        mp_labelPlayerName->setFrameShape(QFrame::NoFrame);
        mp_labelPlayerName->setScaledContents(false);
        mp_labelPlayerName->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        horizontalLayout->addWidget(mp_labelPlayerName);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        mp_table = new client::CardListWidget(LocalPlayerWidget);
        mp_table->setObjectName(QStringLiteral("mp_table"));
        sizePolicy2.setHeightForWidth(mp_table->sizePolicy().hasHeightForWidth());
        mp_table->setSizePolicy(sizePolicy2);
        mp_table->setMinimumSize(QSize(0, 75));

        verticalLayout->addWidget(mp_table);

        mp_hand = new client::CardListWidget(LocalPlayerWidget);
        mp_hand->setObjectName(QStringLiteral("mp_hand"));
        sizePolicy2.setHeightForWidth(mp_hand->sizePolicy().hasHeightForWidth());
        mp_hand->setSizePolicy(sizePolicy2);
        mp_hand->setMinimumSize(QSize(0, 75));

        verticalLayout->addWidget(mp_hand);


        horizontalLayout_3->addLayout(verticalLayout);


        retranslateUi(LocalPlayerWidget);

        QMetaObject::connectSlotsByName(LocalPlayerWidget);
    } // setupUi

    void retranslateUi(QWidget *LocalPlayerWidget)
    {
        LocalPlayerWidget->setWindowTitle(QApplication::translate("LocalPlayerWidget", "Form", nullptr));
        mp_labelAvatar->setText(QString());
#ifndef QT_NO_TOOLTIP
        mp_buttonEndTurn->setToolTip(QApplication::translate("LocalPlayerWidget", "End of your turn", nullptr));
#endif // QT_NO_TOOLTIP
        mp_buttonEndTurn->setStyleSheet(QString());
#ifndef QT_NO_TOOLTIP
        mp_buttonPass->setToolTip(QApplication::translate("LocalPlayerWidget", "Do not react - you will lose a life point,", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        mp_buttonDiscard->setToolTip(QApplication::translate("LocalPlayerWidget", "Discard cards before end of your turn.", nullptr));
#endif // QT_NO_TOOLTIP
        mp_labelPlayerName->setText(QApplication::translate("LocalPlayerWidget", "{PLAYERNAME}", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LocalPlayerWidget: public Ui_LocalPlayerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCALPLAYERWIDGET_H
