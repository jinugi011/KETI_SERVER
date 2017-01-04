#pragma once

#include <QFileInfo>
#include <QMessageBox>
#include <QFileDialog>

#include <QtWidgets/QMainWindow>
#include "ui_KETI_SERVER.h"
#include "use_opencv.h"
#include "threads\PlayerThread.h"
#include "threads\SavingThread.h"
#include "ui/VideoView.h"
#include "FrameLabel.h"


namespace Ui {
	class KETI_SERVER;
}
class KETI_SERVER : public QMainWindow
{
    Q_OBJECT

public:
    KETI_SERVER(QWidget *parent = Q_NULLPTR);
	~KETI_SERVER();
	
	void setCodec(int codec);
	void set_useVideoCodec(bool use);

private:
    Ui::KETI_SERVERClass ui;
	QFileInfo file[6];
	QString filename[6];
	PlayerThread *playerThread[6]; //비디오 재생 쓰레드 
	FrameLabel *originalFrame[6];
	SavingThread *vidSaver[6];
	bool isFileLoaded;
	int index;

	ImageProcessingFlags imageProcessingFlags;
	int codec;
	bool useVideoCodec;
	MagnifyOptions *magnifyOptionsTab;

	void OpenFile(QString name, int width, int height, double fps,int index);
	void InitMain();
	void ExitButtonClicked();
	QString getFormattedTime(int time);
	void handleOriginalWindow(bool doEmit);

	void stopPlayerThread();


public slots:
	void newMouseData(struct MouseData mouseData);
	void newMouseDataOriginalFrame(struct MouseData mouseData);
	void updateMouseCursorPosLabel();
	void updateMouseCursorPosLabelOriginalFrame();
	void endOfFrame_action();
	void endOfSaving_action();
	void updateProgressBar(int frame);

private slots:
	void updateFrame(const QImage &frame);
	void updateOriginalFrame(const QImage &frame);
	void updatePlayerThreadStats(struct ThreadStatisticsData statData);
	void handleContextMenuAction(QAction *action);
	void play();
	void stop();
	void pause();
	void setTime();
	void hideSettings();
	void save_action();
	void handleTabChange(int index);

signals:
	void newImageProcessingFlags(struct ImageProcessingFlags imageProcessingFlags);
	void setROI(QRect roi);

};
