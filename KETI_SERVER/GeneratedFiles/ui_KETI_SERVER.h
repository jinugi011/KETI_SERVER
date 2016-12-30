/********************************************************************************
** Form generated from reading UI file 'KETI_SERVER.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KETI_SERVER_H
#define UI_KETI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KETI_SERVERClass
{
public:
    QAction *actionTOP;
    QAction *actionOPEN_BOTTOM;
    QAction *actionOPEN_LEFT;
    QAction *actionOPEN_RIGHT;
    QAction *actionOPEN_FRONT;
    QAction *actionOPEN_BACK;
    QAction *actionEXIT;
    QWidget *centralWidget;
    QPushButton *btn_stream;
    QPushButton *btn_exit;
    QFrame *framevideo;
    QFrame *frame_video_output;
    QMenuBar *menuBar;
    QMenu *menuFILE_OPEN;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *KETI_SERVERClass)
    {
        if (KETI_SERVERClass->objectName().isEmpty())
            KETI_SERVERClass->setObjectName(QStringLiteral("KETI_SERVERClass"));
        KETI_SERVERClass->resize(1238, 934);
        actionTOP = new QAction(KETI_SERVERClass);
        actionTOP->setObjectName(QStringLiteral("actionTOP"));
        actionOPEN_BOTTOM = new QAction(KETI_SERVERClass);
        actionOPEN_BOTTOM->setObjectName(QStringLiteral("actionOPEN_BOTTOM"));
        actionOPEN_LEFT = new QAction(KETI_SERVERClass);
        actionOPEN_LEFT->setObjectName(QStringLiteral("actionOPEN_LEFT"));
        actionOPEN_RIGHT = new QAction(KETI_SERVERClass);
        actionOPEN_RIGHT->setObjectName(QStringLiteral("actionOPEN_RIGHT"));
        actionOPEN_FRONT = new QAction(KETI_SERVERClass);
        actionOPEN_FRONT->setObjectName(QStringLiteral("actionOPEN_FRONT"));
        actionOPEN_BACK = new QAction(KETI_SERVERClass);
        actionOPEN_BACK->setObjectName(QStringLiteral("actionOPEN_BACK"));
        actionEXIT = new QAction(KETI_SERVERClass);
        actionEXIT->setObjectName(QStringLiteral("actionEXIT"));
        centralWidget = new QWidget(KETI_SERVERClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btn_stream = new QPushButton(centralWidget);
        btn_stream->setObjectName(QStringLiteral("btn_stream"));
        btn_stream->setGeometry(QRect(1130, 10, 101, 61));
        btn_exit = new QPushButton(centralWidget);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));
        btn_exit->setGeometry(QRect(1130, 70, 101, 61));
        framevideo = new QFrame(centralWidget);
        framevideo->setObjectName(QStringLiteral("framevideo"));
        framevideo->setGeometry(QRect(10, 10, 1111, 431));
        framevideo->setFrameShape(QFrame::StyledPanel);
        framevideo->setFrameShadow(QFrame::Raised);
        frame_video_output = new QFrame(centralWidget);
        frame_video_output->setObjectName(QStringLiteral("frame_video_output"));
        frame_video_output->setGeometry(QRect(10, 450, 1111, 431));
        frame_video_output->setFrameShape(QFrame::StyledPanel);
        frame_video_output->setFrameShadow(QFrame::Raised);
        KETI_SERVERClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(KETI_SERVERClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1238, 21));
        menuFILE_OPEN = new QMenu(menuBar);
        menuFILE_OPEN->setObjectName(QStringLiteral("menuFILE_OPEN"));
        KETI_SERVERClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(KETI_SERVERClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        KETI_SERVERClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(KETI_SERVERClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        KETI_SERVERClass->setStatusBar(statusBar);

        menuBar->addAction(menuFILE_OPEN->menuAction());
        menuFILE_OPEN->addAction(actionTOP);
        menuFILE_OPEN->addAction(actionOPEN_BOTTOM);
        menuFILE_OPEN->addAction(actionOPEN_LEFT);
        menuFILE_OPEN->addAction(actionOPEN_RIGHT);
        menuFILE_OPEN->addAction(actionOPEN_FRONT);
        menuFILE_OPEN->addAction(actionOPEN_BACK);
        menuFILE_OPEN->addSeparator();
        menuFILE_OPEN->addAction(actionEXIT);

        retranslateUi(KETI_SERVERClass);
        QObject::connect(btn_exit, SIGNAL(clicked()), KETI_SERVERClass, SLOT(close()));
        QObject::connect(actionEXIT, SIGNAL(toggled(bool)), KETI_SERVERClass, SLOT(close()));

        QMetaObject::connectSlotsByName(KETI_SERVERClass);
    } // setupUi

    void retranslateUi(QMainWindow *KETI_SERVERClass)
    {
        KETI_SERVERClass->setWindowTitle(QApplication::translate("KETI_SERVERClass", "KETI_SERVER", Q_NULLPTR));
        actionTOP->setText(QApplication::translate("KETI_SERVERClass", "OPEN TOP", Q_NULLPTR));
        actionOPEN_BOTTOM->setText(QApplication::translate("KETI_SERVERClass", "OPEN BOTTOM", Q_NULLPTR));
        actionOPEN_LEFT->setText(QApplication::translate("KETI_SERVERClass", "OPEN LEFT", Q_NULLPTR));
        actionOPEN_RIGHT->setText(QApplication::translate("KETI_SERVERClass", "OPEN RIGHT", Q_NULLPTR));
        actionOPEN_FRONT->setText(QApplication::translate("KETI_SERVERClass", "OPEN FRONT", Q_NULLPTR));
        actionOPEN_BACK->setText(QApplication::translate("KETI_SERVERClass", "OPEN BACK", Q_NULLPTR));
        actionEXIT->setText(QApplication::translate("KETI_SERVERClass", "EXIT", Q_NULLPTR));
        btn_stream->setText(QApplication::translate("KETI_SERVERClass", "Stream Out", Q_NULLPTR));
        btn_exit->setText(QApplication::translate("KETI_SERVERClass", "EXIT", Q_NULLPTR));
        menuFILE_OPEN->setTitle(QApplication::translate("KETI_SERVERClass", "FILE OPEN", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class KETI_SERVERClass: public Ui_KETI_SERVERClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KETI_SERVER_H
