/********************************************************************************
** Form generated from reading UI file 'chatwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGET_H
#define UI_CHATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *mp_chatView;
    QLineEdit *mp_messageBox;

    void setupUi(QWidget *ChatWidget)
    {
        if (ChatWidget->objectName().isEmpty())
            ChatWidget->setObjectName(QStringLiteral("ChatWidget"));
        ChatWidget->resize(264, 220);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChatWidget->sizePolicy().hasHeightForWidth());
        ChatWidget->setSizePolicy(sizePolicy);
        ChatWidget->setStyleSheet(QLatin1String("QTextBrowser, QLineEdit {\n"
"  background-color: rgba(0, 0, 0, 32);\n"
"  border: 1px solid gray;\n"
"}\n"
"QScrollBar:vertical {\n"
"	border: 1px solid grey;\n"
"	background: rgba(0, 0, 0, 0);\n"
"	width: 15px;\n"
"	margin: 19px 0 19px 0;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"	background: rgba(0, 0, 0, 32);\n"
"	border-top: 1px solid grey;\n"
"	border-bottom: 1px solid grey;\n"
"	min-height: 45px;\n"
"	margin-top: -1;\n"
"	margin-bottom: -1;\n"
"}\n"
"QScrollBar::add-line:vertical {\n"
"	border: 1px solid grey;\n"
"	background: rgba(0, 0, 0, 32);\n"
"	height: 15px;\n"
"	subcontrol-position: bottom;\n"
"	subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:vertical {\n"
"	border: 1px solid grey;\n"
"	background: rgba(0, 0, 0, 32);\n"
"	height: 15px;\n"
"	subcontrol-position: top;\n"
"	subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {\n"
"	border: 1px solid grey;\n"
"	width: 5px;\n"
"	height: 5px;\n"
"	background: rgb(0, 0, 0, 32);\n"
"}\n"
"Q"
                        "ScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"	background: none;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(ChatWidget);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        mp_chatView = new QTextBrowser(ChatWidget);
        mp_chatView->setObjectName(QStringLiteral("mp_chatView"));
        mp_chatView->setFrameShape(QFrame::StyledPanel);
        mp_chatView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        verticalLayout->addWidget(mp_chatView);

        mp_messageBox = new QLineEdit(ChatWidget);
        mp_messageBox->setObjectName(QStringLiteral("mp_messageBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mp_messageBox->sizePolicy().hasHeightForWidth());
        mp_messageBox->setSizePolicy(sizePolicy1);
        mp_messageBox->setFrame(false);

        verticalLayout->addWidget(mp_messageBox);


        retranslateUi(ChatWidget);

        QMetaObject::connectSlotsByName(ChatWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatWidget)
    {
        ChatWidget->setWindowTitle(QApplication::translate("ChatWidget", "ChatWidget", Q_NULLPTR));
        mp_chatView->setHtml(QApplication::translate("ChatWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChatWidget: public Ui_ChatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET_H
