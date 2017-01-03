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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "FrameLabel.h"

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
    QAction *actionHEVC;
    QAction *actionMpeg_4;
    QAction *actionAV1;
    QWidget *centralWidget;
    QPushButton *btn_stream;
    QPushButton *btn_exit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *playerControlLayout;
    QPushButton *PlayButton;
    QPushButton *StopButton;
    QLabel *currentTimeLabel;
    QSlider *TimeSlider;
    QLabel *totalTimeLabel;
    QCheckBox *LoopCheckBox;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *saveButton;
    QCheckBox *saveOriginalCheckBox;
    QSpacerItem *saveHorizontalSpacer;
    QPushButton *hideSettingsButton;
    QWidget *layoutWidget_2;
    QHBoxLayout *frameLayout_main;
    FrameLabel *frameLabel_main;
    QTabWidget *tabWidget;
    QWidget *InfoTab;
    QGridLayout *gridLayout;
    QLabel *nFramesCapturedLabel;
    QLabel *label_23;
    QLabel *processingRateLabel;
    QLabel *cameraResolutionLabel;
    QLabel *deviceNumberLabel;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *captureRateLabel;
    QLabel *nFramesProcessedLabel;
    QLabel *label_28;
    QLabel *roiLabel;
    QLabel *label_22;
    QLabel *mouseCursorPosLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *label_24;
    QLabel *label;
    QLabel *currentFrameNumberLabel;
    QProgressBar *saveProgressBar;
    QMenuBar *menuBar;
    QMenu *menuFILE_OPEN;
    QMenu *menuCodec;
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
        actionHEVC = new QAction(KETI_SERVERClass);
        actionHEVC->setObjectName(QStringLiteral("actionHEVC"));
        actionMpeg_4 = new QAction(KETI_SERVERClass);
        actionMpeg_4->setObjectName(QStringLiteral("actionMpeg_4"));
        actionAV1 = new QAction(KETI_SERVERClass);
        actionAV1->setObjectName(QStringLiteral("actionAV1"));
        centralWidget = new QWidget(KETI_SERVERClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btn_stream = new QPushButton(centralWidget);
        btn_stream->setObjectName(QStringLiteral("btn_stream"));
        btn_stream->setGeometry(QRect(1130, 10, 101, 61));
        btn_exit = new QPushButton(centralWidget);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));
        btn_exit->setGeometry(QRect(1130, 70, 101, 61));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(684, 250, 431, 67));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        playerControlLayout = new QHBoxLayout();
        playerControlLayout->setSpacing(6);
        playerControlLayout->setObjectName(QStringLiteral("playerControlLayout"));
        PlayButton = new QPushButton(layoutWidget);
        PlayButton->setObjectName(QStringLiteral("PlayButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PlayButton->sizePolicy().hasHeightForWidth());
        PlayButton->setSizePolicy(sizePolicy);
        PlayButton->setCheckable(false);

        playerControlLayout->addWidget(PlayButton);

        StopButton = new QPushButton(layoutWidget);
        StopButton->setObjectName(QStringLiteral("StopButton"));
        sizePolicy.setHeightForWidth(StopButton->sizePolicy().hasHeightForWidth());
        StopButton->setSizePolicy(sizePolicy);

        playerControlLayout->addWidget(StopButton);

        currentTimeLabel = new QLabel(layoutWidget);
        currentTimeLabel->setObjectName(QStringLiteral("currentTimeLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(currentTimeLabel->sizePolicy().hasHeightForWidth());
        currentTimeLabel->setSizePolicy(sizePolicy1);

        playerControlLayout->addWidget(currentTimeLabel);

        TimeSlider = new QSlider(layoutWidget);
        TimeSlider->setObjectName(QStringLiteral("TimeSlider"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(TimeSlider->sizePolicy().hasHeightForWidth());
        TimeSlider->setSizePolicy(sizePolicy2);
        TimeSlider->setOrientation(Qt::Horizontal);

        playerControlLayout->addWidget(TimeSlider);

        totalTimeLabel = new QLabel(layoutWidget);
        totalTimeLabel->setObjectName(QStringLiteral("totalTimeLabel"));
        sizePolicy1.setHeightForWidth(totalTimeLabel->sizePolicy().hasHeightForWidth());
        totalTimeLabel->setSizePolicy(sizePolicy1);

        playerControlLayout->addWidget(totalTimeLabel);

        LoopCheckBox = new QCheckBox(layoutWidget);
        LoopCheckBox->setObjectName(QStringLiteral("LoopCheckBox"));

        playerControlLayout->addWidget(LoopCheckBox);


        verticalLayout_2->addLayout(playerControlLayout);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShadow(QFrame::Raised);
        line_2->setFrameShape(QFrame::HLine);

        verticalLayout_2->addWidget(line_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        saveButton = new QPushButton(layoutWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout_2->addWidget(saveButton);

        saveOriginalCheckBox = new QCheckBox(layoutWidget);
        saveOriginalCheckBox->setObjectName(QStringLiteral("saveOriginalCheckBox"));

        horizontalLayout_2->addWidget(saveOriginalCheckBox);

        saveHorizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(saveHorizontalSpacer);

        hideSettingsButton = new QPushButton(layoutWidget);
        hideSettingsButton->setObjectName(QStringLiteral("hideSettingsButton"));

        horizontalLayout_2->addWidget(hideSettingsButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        layoutWidget_2 = new QWidget(centralWidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 0, 1111, 241));
        frameLayout_main = new QHBoxLayout(layoutWidget_2);
        frameLayout_main->setSpacing(6);
        frameLayout_main->setContentsMargins(11, 11, 11, 11);
        frameLayout_main->setObjectName(QStringLiteral("frameLayout_main"));
        frameLayout_main->setContentsMargins(0, 0, 0, 0);
        frameLabel_main = new FrameLabel(layoutWidget_2);
        frameLabel_main->setObjectName(QStringLiteral("frameLabel_main"));
        frameLabel_main->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frameLabel_main->sizePolicy().hasHeightForWidth());
        frameLabel_main->setSizePolicy(sizePolicy3);
        frameLabel_main->setMouseTracking(true);
        frameLabel_main->setAutoFillBackground(true);
        frameLabel_main->setFrameShape(QFrame::Box);
        frameLabel_main->setAlignment(Qt::AlignCenter);

        frameLayout_main->addWidget(frameLabel_main);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 285, 663, 179));
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setMinimumSize(QSize(0, 0));
        InfoTab = new QWidget();
        InfoTab->setObjectName(QStringLiteral("InfoTab"));
        sizePolicy.setHeightForWidth(InfoTab->sizePolicy().hasHeightForWidth());
        InfoTab->setSizePolicy(sizePolicy);
        InfoTab->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(InfoTab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        nFramesCapturedLabel = new QLabel(InfoTab);
        nFramesCapturedLabel->setObjectName(QStringLiteral("nFramesCapturedLabel"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(nFramesCapturedLabel->sizePolicy().hasHeightForWidth());
        nFramesCapturedLabel->setSizePolicy(sizePolicy4);
        QFont font;
        font.setPointSize(8);
        nFramesCapturedLabel->setFont(font);
        nFramesCapturedLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(nFramesCapturedLabel, 3, 3, 1, 1);

        label_23 = new QLabel(InfoTab);
        label_23->setObjectName(QStringLiteral("label_23"));
        sizePolicy4.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy4);
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        label_23->setFont(font1);

        gridLayout->addWidget(label_23, 5, 1, 1, 1);

        processingRateLabel = new QLabel(InfoTab);
        processingRateLabel->setObjectName(QStringLiteral("processingRateLabel"));
        sizePolicy4.setHeightForWidth(processingRateLabel->sizePolicy().hasHeightForWidth());
        processingRateLabel->setSizePolicy(sizePolicy4);
        processingRateLabel->setFont(font);

        gridLayout->addWidget(processingRateLabel, 5, 2, 1, 1);

        cameraResolutionLabel = new QLabel(InfoTab);
        cameraResolutionLabel->setObjectName(QStringLiteral("cameraResolutionLabel"));
        sizePolicy4.setHeightForWidth(cameraResolutionLabel->sizePolicy().hasHeightForWidth());
        cameraResolutionLabel->setSizePolicy(sizePolicy4);
        cameraResolutionLabel->setFont(font);
        cameraResolutionLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(cameraResolutionLabel, 2, 2, 1, 1);

        deviceNumberLabel = new QLabel(InfoTab);
        deviceNumberLabel->setObjectName(QStringLiteral("deviceNumberLabel"));
        sizePolicy4.setHeightForWidth(deviceNumberLabel->sizePolicy().hasHeightForWidth());
        deviceNumberLabel->setSizePolicy(sizePolicy4);
        deviceNumberLabel->setFont(font);
        deviceNumberLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(deviceNumberLabel, 1, 2, 1, 1);

        label_26 = new QLabel(InfoTab);
        label_26->setObjectName(QStringLiteral("label_26"));
        sizePolicy4.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy4);
        label_26->setFont(font1);
        label_26->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_26, 2, 1, 1, 1);

        label_27 = new QLabel(InfoTab);
        label_27->setObjectName(QStringLiteral("label_27"));
        sizePolicy4.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy4);
        label_27->setFont(font1);
        label_27->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_27, 3, 1, 1, 1);

        captureRateLabel = new QLabel(InfoTab);
        captureRateLabel->setObjectName(QStringLiteral("captureRateLabel"));
        captureRateLabel->setEnabled(true);
        sizePolicy4.setHeightForWidth(captureRateLabel->sizePolicy().hasHeightForWidth());
        captureRateLabel->setSizePolicy(sizePolicy4);
        captureRateLabel->setFont(font);

        gridLayout->addWidget(captureRateLabel, 3, 2, 1, 1);

        nFramesProcessedLabel = new QLabel(InfoTab);
        nFramesProcessedLabel->setObjectName(QStringLiteral("nFramesProcessedLabel"));
        sizePolicy4.setHeightForWidth(nFramesProcessedLabel->sizePolicy().hasHeightForWidth());
        nFramesProcessedLabel->setSizePolicy(sizePolicy4);
        nFramesProcessedLabel->setFont(font);
        nFramesProcessedLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(nFramesProcessedLabel, 5, 3, 1, 1);

        label_28 = new QLabel(InfoTab);
        label_28->setObjectName(QStringLiteral("label_28"));
        sizePolicy4.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy4);
        label_28->setFont(font1);

        gridLayout->addWidget(label_28, 6, 1, 1, 1);

        roiLabel = new QLabel(InfoTab);
        roiLabel->setObjectName(QStringLiteral("roiLabel"));
        sizePolicy4.setHeightForWidth(roiLabel->sizePolicy().hasHeightForWidth());
        roiLabel->setSizePolicy(sizePolicy4);
        roiLabel->setFont(font);

        gridLayout->addWidget(roiLabel, 6, 2, 1, 1);

        label_22 = new QLabel(InfoTab);
        label_22->setObjectName(QStringLiteral("label_22"));
        sizePolicy4.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy4);
        label_22->setFont(font1);

        gridLayout->addWidget(label_22, 7, 1, 1, 1);

        mouseCursorPosLabel = new QLabel(InfoTab);
        mouseCursorPosLabel->setObjectName(QStringLiteral("mouseCursorPosLabel"));
        sizePolicy4.setHeightForWidth(mouseCursorPosLabel->sizePolicy().hasHeightForWidth());
        mouseCursorPosLabel->setSizePolicy(sizePolicy4);
        mouseCursorPosLabel->setFont(font);

        gridLayout->addWidget(mouseCursorPosLabel, 7, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        gridLayout->addLayout(horizontalLayout, 8, 4, 1, 1);

        label_24 = new QLabel(InfoTab);
        label_24->setObjectName(QStringLiteral("label_24"));
        sizePolicy4.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy4);
        label_24->setFont(font1);
        label_24->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_24, 1, 1, 1, 1);

        label = new QLabel(InfoTab);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        gridLayout->addWidget(label, 4, 1, 1, 1);

        currentFrameNumberLabel = new QLabel(InfoTab);
        currentFrameNumberLabel->setObjectName(QStringLiteral("currentFrameNumberLabel"));
        currentFrameNumberLabel->setFont(font);

        gridLayout->addWidget(currentFrameNumberLabel, 4, 2, 1, 1);

        tabWidget->addTab(InfoTab, QString());
        saveProgressBar = new QProgressBar(centralWidget);
        saveProgressBar->setObjectName(QStringLiteral("saveProgressBar"));
        saveProgressBar->setGeometry(QRect(20, 250, 663, 20));
        saveProgressBar->setValue(0);
        KETI_SERVERClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(KETI_SERVERClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1238, 21));
        menuFILE_OPEN = new QMenu(menuBar);
        menuFILE_OPEN->setObjectName(QStringLiteral("menuFILE_OPEN"));
        menuCodec = new QMenu(menuBar);
        menuCodec->setObjectName(QStringLiteral("menuCodec"));
        KETI_SERVERClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(KETI_SERVERClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        KETI_SERVERClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(KETI_SERVERClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        KETI_SERVERClass->setStatusBar(statusBar);

        menuBar->addAction(menuFILE_OPEN->menuAction());
        menuBar->addAction(menuCodec->menuAction());
        menuFILE_OPEN->addAction(actionTOP);
        menuFILE_OPEN->addAction(actionOPEN_BOTTOM);
        menuFILE_OPEN->addAction(actionOPEN_LEFT);
        menuFILE_OPEN->addAction(actionOPEN_RIGHT);
        menuFILE_OPEN->addAction(actionOPEN_FRONT);
        menuFILE_OPEN->addAction(actionOPEN_BACK);
        menuFILE_OPEN->addSeparator();
        menuFILE_OPEN->addAction(actionEXIT);
        menuCodec->addAction(actionHEVC);
        menuCodec->addAction(actionMpeg_4);
        menuCodec->addAction(actionAV1);
        menuCodec->addSeparator();

        retranslateUi(KETI_SERVERClass);
        QObject::connect(btn_exit, SIGNAL(clicked()), KETI_SERVERClass, SLOT(close()));
        QObject::connect(actionEXIT, SIGNAL(toggled(bool)), KETI_SERVERClass, SLOT(close()));

        tabWidget->setCurrentIndex(0);


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
        actionHEVC->setText(QApplication::translate("KETI_SERVERClass", "HEVC", Q_NULLPTR));
        actionMpeg_4->setText(QApplication::translate("KETI_SERVERClass", "Mpeg-4", Q_NULLPTR));
        actionAV1->setText(QApplication::translate("KETI_SERVERClass", "AV1", Q_NULLPTR));
        btn_stream->setText(QApplication::translate("KETI_SERVERClass", "Stream Out", Q_NULLPTR));
        btn_exit->setText(QApplication::translate("KETI_SERVERClass", "EXIT", Q_NULLPTR));
        PlayButton->setText(QApplication::translate("KETI_SERVERClass", "Play", Q_NULLPTR));
        PlayButton->setShortcut(QApplication::translate("KETI_SERVERClass", "Return", Q_NULLPTR));
        StopButton->setText(QApplication::translate("KETI_SERVERClass", "Stop", Q_NULLPTR));
        currentTimeLabel->setText(QApplication::translate("KETI_SERVERClass", "00:00", Q_NULLPTR));
        totalTimeLabel->setText(QApplication::translate("KETI_SERVERClass", "00:00", Q_NULLPTR));
        LoopCheckBox->setText(QApplication::translate("KETI_SERVERClass", "Loop", Q_NULLPTR));
        saveButton->setText(QApplication::translate("KETI_SERVERClass", "Save", Q_NULLPTR));
        saveOriginalCheckBox->setText(QApplication::translate("KETI_SERVERClass", "Save Original", Q_NULLPTR));
        hideSettingsButton->setText(QApplication::translate("KETI_SERVERClass", "Hide Settings", Q_NULLPTR));
        nFramesCapturedLabel->setText(QString());
        label_23->setText(QApplication::translate("KETI_SERVERClass", "Processing Rate:", Q_NULLPTR));
        processingRateLabel->setText(QString());
        label_26->setText(QApplication::translate("KETI_SERVERClass", "Resolution:", Q_NULLPTR));
        label_27->setText(QApplication::translate("KETI_SERVERClass", "Framerate:", Q_NULLPTR));
        captureRateLabel->setText(QString());
        nFramesProcessedLabel->setText(QString());
        label_28->setText(QApplication::translate("KETI_SERVERClass", "ROI:", Q_NULLPTR));
        roiLabel->setText(QString());
        label_22->setText(QApplication::translate("KETI_SERVERClass", "Cursor:", Q_NULLPTR));
        mouseCursorPosLabel->setText(QString());
        label_24->setText(QApplication::translate("KETI_SERVERClass", "Filename:", Q_NULLPTR));
        label->setText(QApplication::translate("KETI_SERVERClass", "Framenumber:", Q_NULLPTR));
        currentFrameNumberLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(InfoTab), QApplication::translate("KETI_SERVERClass", "Video Information", Q_NULLPTR));
        menuFILE_OPEN->setTitle(QApplication::translate("KETI_SERVERClass", "FILE OPEN", Q_NULLPTR));
        menuCodec->setTitle(QApplication::translate("KETI_SERVERClass", "Codec", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class KETI_SERVERClass: public Ui_KETI_SERVERClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KETI_SERVER_H
