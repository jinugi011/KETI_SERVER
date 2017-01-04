#include "KETI_SERVER.h"
#include <iostream>
#include <string>
#include "ui_VideoView.h"


using namespace cv;
using namespace std;

KETI_SERVER::KETI_SERVER(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//이벤트 처리 

	index = 0;

	for (int i = 0; i < 6; i++)
	{
		originalFrame[i] = new FrameLabel(this);
		originalFrame[i]->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
		originalFrame[i]->setAutoFillBackground(true);
		originalFrame[i]->setFrameShape(QFrame::Box);
		originalFrame[i]->setAlignment(ui.frameLabel_main->alignment());
		originalFrame[i]->setMouseTracking(true);
		originalFrame[i]->menu->clear();
		//originalFrame[index]->menu->addActions(ui.frameLabel->menu->actions());
		ui.frameLayout_main->addWidget(originalFrame[i], 0, 0);
		originalFrame[i]->setVisible(false);

		this->file[i] = QFileInfo("D:\\VR_SAMPLE_VIDEO\\4kvideo_15.mp4");
		filename[i] = file[i].fileName();
		connect(originalFrame[i], SIGNAL(onMouseMoveEvent()), this, SLOT(updateMouseCursorPosLabelOriginalFrame())); //이벤트 걸기 

	}
	
	// Initialize ImageProcessingFlags structure
	imageProcessingFlags.grayscaleOn = false;
	imageProcessingFlags.laplaceMagnifyOn = false;
	imageProcessingFlags.waveletMagnifyOn = false;
	imageProcessingFlags.colorMagnifyOn = false;


	InitMain();

}


KETI_SERVER::~KETI_SERVER()
{
	if (isFileLoaded) {

	
		for (int i = 0; i < 6; i++)
		{
			// Stop playerThread
			if (playerThread[i]->isRunning())
				stopPlayerThread();

			// Release File
			if (playerThread[i]->releaseFile())
				qDebug() << "[" << filename << "] Video succesfully released.";
			else
				qDebug() << "[" << filename << "] WARNING: Video already released.";
		}
	}
	// Delete Threads
	delete playerThread;
	delete vidSaver;
	// Delete UI integrated Pointer
	delete originalFrame;
	delete magnifyOptionsTab;
	// Delete UI
	//delete ui.retranslateUi;
}

void KETI_SERVER::ExitButtonClicked()
{

}

void KETI_SERVER::InitMain()
{
	
	string imagename = "./test.jpg";
	/*cv::Mat image;
	image = imread(imagename, IMREAD_COLOR);
	if (image.empty())
	{
		return;
	}*/

	//IplImage *image;
	//image = cvLoadImage("./test.jpg");
	//cvNamedWindow("YANG JIN", CV_WINDOW_AUTOSIZE);
	//cvShowImage("YANG JIN", image);
	//cvReleaseImage(&image);
	//cvvShowImage("YANG JIN", image);

	OpenFile("YANG", 100, 100, 60, 0);
	

}


void KETI_SERVER::OpenFile(QString name, int width, int height, double fps,int index)
{

	// Set frame label text
	ui.frameLabel_main->setText(tr("Loading Video..."));
	QString filepath = file[index].absoluteFilePath();
	std::string stringFilepath = filepath.toStdString();
	// create player thread
	playerThread[index] = new PlayerThread(stringFilepath, width, height, fps);


	if (playerThread[index]->loadFile())
	{
		ui.frameLabel_main->setText("Video loaded");

		// Create MagnifyOptions tab and set current
		this->magnifyOptionsTab = new MagnifyOptions();
		ui.tabWidget->insertTab(0, magnifyOptionsTab, tr("Options"));
		ui.tabWidget->setCurrentIndex(0);
		ui.InfoTab->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Ignored);

		// Setup signal/slot connections
		connect(ui.tabWidget, SIGNAL(currentChanged(int)), this, SLOT(handleTabChange(int)));
		connect(this, SIGNAL(newImageProcessingFlags(struct ImageProcessingFlags)), playerThread[index], SLOT(updateImageProcessingFlags(struct ImageProcessingFlags)));
		connect(this, SIGNAL(setROI(QRect)), playerThread[index], SLOT(setROI(QRect)));
		connect(playerThread[index], SIGNAL(maxLevels(int)), magnifyOptionsTab, SLOT(setMaxLevel(int)));
		// Setup signal/slot connections for MagnifyOptions
		connect(magnifyOptionsTab, SIGNAL(newImageProcessingSettings(struct ImageProcessingSettings)), playerThread[index], SLOT(updateImageProcessingSettings(struct ImageProcessingSettings)));
		connect(magnifyOptionsTab, SIGNAL(newImageProcessingFlags(struct ImageProcessingFlags)), playerThread[index], SLOT(updateImageProcessingFlags(struct ImageProcessingFlags)));
		// Setup signal/slot for playerThread
		connect(playerThread[index], SIGNAL(endOfFrame()), this, SLOT(endOfFrame_action()));
		connect(playerThread[index], SIGNAL(updateStatisticsInGUI(struct ThreadStatisticsData)), this, SLOT(updateplayerThreadStats(struct ThreadStatisticsData)));
		connect(ui.PlayButton, SIGNAL(clicked()), this, SLOT(play()));
		connect(ui.StopButton, SIGNAL(clicked()), this, SLOT(stop()));
		connect(ui.TimeSlider, SIGNAL(sliderPressed()), playerThread[index], SLOT(pauseThread()));
		connect(ui.TimeSlider, SIGNAL(sliderReleased()), this, SLOT(setTime()));

		// Connect frames emitting
		connect(playerThread[index], SIGNAL(newFrame(QImage)), this, SLOT(updateFrame(QImage)));
		connect(playerThread[index], SIGNAL(origFrame(QImage)), this, SLOT(updateOriginalFrame(QImage)));

		// Create the SavingThread and connect buttons to it's meant functions
		vidSaver[index] = new SavingThread();
		connect(ui.saveButton, SIGNAL(clicked()), this, SLOT(save_action()));
		connect(vidSaver[index], SIGNAL(updateProgress(int)), this, SLOT(updateProgressBar(int)));
		connect(vidSaver[index], SIGNAL(endOfSaving()), this, SLOT(endOfSaving_action()));
		ui.saveProgressBar->hide();

		connect(ui.frameLabel_main, SIGNAL(newMouseData(struct MouseData)), this, SLOT(newMouseData(struct MouseData)));
		connect(originalFrame[index], SIGNAL(newMouseData(struct MouseData)), this, SLOT(newMouseData(struct MouseData)));

		// Set initial data in player thread
		emit setROI(QRect(0, 0, playerThread[index]->getInputSourceWidth(), playerThread[index]->getInputSourceHeight()));
		emit newImageProcessingFlags(imageProcessingFlags);

		// Start capturing frames from camera
		playerThread[index]->start((QThread::Priority)index);

		ui.deviceNumberLabel->setText(filename[index]);
		ui.cameraResolutionLabel->setText(QString::number(playerThread[index]->getInputSourceWidth()) + QString("x") + QString::number(playerThread[index]->getInputSourceHeight()));
		ui.totalTimeLabel->setText(getFormattedTime(playerThread[index]->getInputFrameLength() / playerThread[index]->getFPS()));
		ui.TimeSlider->setMaximum(playerThread[index]->getInputFrameLength());
		// Set internal flag and return
		isFileLoaded = true;
		return;
	}
	else
		return;
}


void KETI_SERVER::updateOriginalFrame(const QImage &frame)
{
	// Display frame
	originalFrame[index]->setPixmap(QPixmap::fromImage(frame).scaled(ui.frameLabel_main->width(), ui.frameLabel_main->height(), Qt::KeepAspectRatio));
}

QString KETI_SERVER::getFormattedTime(int timeInSeconds) {

	int seconds = (int)(timeInSeconds) % 60;
	int minutes = (int)((timeInSeconds / 60) % 60);
	int hours = (int)((timeInSeconds / (60 * 60)) % 24);

	QTime t(hours, minutes, seconds);
	if (hours == 0)
		return t.toString("mm:ss");
	else
		return t.toString("h:mm:ss");
}

void KETI_SERVER::endOfFrame_action()
{
	ui.TimeSlider->setValue(0);
	ui.PlayButton->setText("Play");
	playerThread[index]->stopAction();

	if (ui.LoopCheckBox->isChecked())
		play();
}

void KETI_SERVER::stopPlayerThread()
{
	qDebug() << "[" << filename << "] About to stop player thread...";
	playerThread[index]->stop();
	playerThread[index]->wait();
	qDebug() << "[" << filename << "] Player thread successfully stopped.";
}

void KETI_SERVER::updatePlayerThreadStats(struct ThreadStatisticsData statData)
{
	ui.TimeSlider->setValue(statData.nFramesProcessed);
	ui.currentTimeLabel->setText(getFormattedTime(statData.nFramesProcessed / (int)playerThread[index]->getFPS()));
	ui.captureRateLabel->setText(QString::number(statData.averageFPS));
	ui.currentFrameNumberLabel->setText(QString::number(statData.nFramesProcessed));

	// Show processing rate in processingRateLabel
	ui.processingRateLabel->setText(QString::number(statData.averageVidProcessingFPS) + " fps");
	// Show ROI information in roiLabel
	ui.roiLabel->setText(QString("(") + QString::number(playerThread[index]->getCurrentROI().x()) + QString(",") +
		QString::number(playerThread[index]->getCurrentROI().y()) + QString(") ") +
		QString::number(playerThread[index]->getCurrentROI().width()) +
		QString("x") + QString::number(playerThread[index]->getCurrentROI().height()));
}

void KETI_SERVER::updateFrame(const QImage &frame)
{
	int w = ui.frameLabel_main->width();
	int h = ui.frameLabel_main->height();
	// Display frame
	ui.frameLabel_main->setPixmap(QPixmap::fromImage(frame).scaled(w, h, Qt::KeepAspectRatio));
}



void KETI_SERVER::updateMouseCursorPosLabel()
{
	// Update mouse cursor position in mouseCursorPosLabel
	ui.mouseCursorPosLabel->setText(QString("(") + QString::number(ui.frameLabel_main->getMouseCursorPos().x()) +
		QString(",") + QString::number(ui.frameLabel_main->getMouseCursorPos().y()) +
		QString(")"));

	// Show pixel cursor position if camera is connected (image is being shown)
	if (ui.frameLabel_main->pixmap() != 0)
	{
		// Scaling factor calculation depends on whether frame is scaled to fit label or not
		if (!ui.frameLabel_main->hasScaledContents())
		{
			//double xScalingFactor = ((double)ui.frameLabel_main.getMouseCursorPos().x() - ((ui.frameLabel_main->width() - ui.frameLabel_main->pixmap()->width()) / 2)) / (double)ui.frameLabel_main->pixmap()->width();
			//double yScalingFactor = ((double)ui.frameLabel_main.getMouseCursorPos().y() - ((ui.frameLabel_main->height() - ui.frameLabel_main->pixmap()->height()) / 2)) / (double)ui.frameLabel_main->pixmap()->height();


			double xScalingFactor = ((double)ui.frameLabel_main->getMouseCursorPos().x() - ((ui.frameLabel_main->width() - ui.frameLabel_main->pixmap()->width()) / 2)) / (double)ui.frameLabel_main->pixmap()->width();
			double yScalingFactor = ((double)ui.frameLabel_main->getMouseCursorPos().y() - ((ui.frameLabel_main->height() - ui.frameLabel_main->pixmap()->height()) / 2)) / (double)ui.frameLabel_main->pixmap()->height();


			ui.mouseCursorPosLabel->setText(ui.mouseCursorPosLabel->text() +
				QString(" [") + QString::number((int)(xScalingFactor*playerThread[index]->getCurrentROI().width())) +
				QString(",") + QString::number((int)(yScalingFactor*playerThread[index]->getCurrentROI().height())) +
				QString("]"));
		}
		else
		{
			double xScalingFactor = (double)ui.frameLabel_main->getMouseCursorPos().x() / (double)ui.frameLabel_main->width();
			double yScalingFactor = (double)ui.frameLabel_main->getMouseCursorPos().y() / (double)ui.frameLabel_main->height();

			ui.mouseCursorPosLabel->setText(ui.mouseCursorPosLabel->text() +
				QString(" [") + QString::number((int)(xScalingFactor*playerThread[index]->getCurrentROI().width())) +
				QString(",") + QString::number((int)(yScalingFactor*playerThread[index]->getCurrentROI().height())) +
				QString("]"));
		}
	}
}


void KETI_SERVER::newMouseData(struct MouseData mouseData)
{
	// Local variable(s)
	int x_temp, y_temp, width_temp, height_temp;
	QRect selectionBox;

	// Set ROI
	if (mouseData.leftButtonRelease)
	{
		double xScalingFactor;
		double yScalingFactor;
		double wScalingFactor;
		double hScalingFactor;

		// Selection box calculation depends on whether frame is scaled to fit label or not
		if (!ui.frameLabel_main->hasScaledContents())
		{
			xScalingFactor = ((double)mouseData.selectionBox.x() - ((ui.frameLabel_main->width() - ui.frameLabel_main->pixmap()->width()) / 2)) / (double)ui.frameLabel_main->pixmap()->width();
			yScalingFactor = ((double)mouseData.selectionBox.y() - ((ui.frameLabel_main->height() - ui.frameLabel_main->pixmap()->height()) / 2)) / (double)ui.frameLabel_main->pixmap()->height();
			wScalingFactor = (double)playerThread[index]->getCurrentROI().width() / (double)ui.frameLabel_main->pixmap()->width();
			hScalingFactor = (double)playerThread[index]->getCurrentROI().height() / (double)ui.frameLabel_main->pixmap()->height();
		}
		else
		{
			xScalingFactor = (double)mouseData.selectionBox.x() / (double)ui.frameLabel_main->width();
			yScalingFactor = (double)mouseData.selectionBox.y() / (double)ui.frameLabel_main->height();
			wScalingFactor = (double)playerThread[index]->getCurrentROI().width() / (double)ui.frameLabel_main->width();
			hScalingFactor = (double)playerThread[index]->getCurrentROI().height() / (double)ui.frameLabel_main->height();
		}

		// Set selection box properties (new ROI)
		selectionBox.setX(xScalingFactor*playerThread[index]->getCurrentROI().width() + playerThread[index]->getCurrentROI().x());
		selectionBox.setY(yScalingFactor*playerThread[index]->getCurrentROI().height() + playerThread[index]->getCurrentROI().y());
		selectionBox.setWidth(wScalingFactor*mouseData.selectionBox.width());
		selectionBox.setHeight(hScalingFactor*mouseData.selectionBox.height());

		// Check if selection box has NON-ZERO dimensions
		if ((selectionBox.width() != 0) && ((selectionBox.height()) != 0))
		{
			// Selection box can also be drawn from bottom-right to top-left corner
			if (selectionBox.width()<0)
			{
				x_temp = selectionBox.x();
				width_temp = selectionBox.width();
				selectionBox.setX(x_temp + selectionBox.width());
				selectionBox.setWidth(width_temp*-1);
			}
			if (selectionBox.height()<0)
			{
				y_temp = selectionBox.y();
				height_temp = selectionBox.height();
				selectionBox.setY(y_temp + selectionBox.height());
				selectionBox.setHeight(height_temp*-1);
			}

			// Check if selection box is not outside window
			if ((selectionBox.x()<0) || (selectionBox.y()<0) ||
				((selectionBox.x() + selectionBox.width())>(playerThread[index]->getCurrentROI().x() + playerThread[index]->getCurrentROI().width())) ||
				((selectionBox.y() + selectionBox.height())>(playerThread[index]->getCurrentROI().y() + playerThread[index]->getCurrentROI().height())) ||
				(selectionBox.x()<playerThread[index]->getCurrentROI().x()) ||
				(selectionBox.y()<playerThread[index]->getCurrentROI().y()))
			{
				// Display error message
				QMessageBox::warning(this, tr("ERROR:"), tr("Selection box outside range. Please try again."));
			}
			// Set ROI
			else
				emit setROI(selectionBox);
		}
	}
}



void KETI_SERVER::updateMouseCursorPosLabelOriginalFrame()
{
	// Update mouse cursor position in mouseCursorPosLabel
	ui.mouseCursorPosLabel->setText(QString("(") + QString::number(originalFrame[index]->getMouseCursorPos().x()) +
		QString(",") + QString::number(originalFrame[index]->getMouseCursorPos().y()) +
		QString(")"));

	// Show pixel cursor position if camera is connected (image is being shown)
	if (originalFrame[index]->pixmap() != 0)
	{
		// Scaling factor calculation depends on whether frame is scaled to fit label or not
		if (!originalFrame[index]->hasScaledContents())
		{
			double xScalingFactor = ((double)originalFrame[index]->getMouseCursorPos().x() - ((originalFrame[index]->width() - originalFrame[index]->pixmap()->width()) / 2)) / (double)originalFrame[index]->pixmap()->width();
			double yScalingFactor = ((double)originalFrame[index]->getMouseCursorPos().y() - ((originalFrame[index]->height() - originalFrame[index]->pixmap()->height()) / 2)) / (double)originalFrame[index]->pixmap()->height();

			ui.mouseCursorPosLabel->setText(ui.mouseCursorPosLabel->text() +
				QString(" [") + QString::number((int)(xScalingFactor*playerThread[index]->getCurrentROI().width())) +
				QString(",") + QString::number((int)(yScalingFactor*playerThread[index]->getCurrentROI().height())) +
				QString("]"));
		}
		else
		{
			double xScalingFactor = (double)originalFrame[index]->getMouseCursorPos().x() / (double)originalFrame[index]->width();
			double yScalingFactor = (double)originalFrame[index]->getMouseCursorPos().y() / (double)originalFrame[index]->height();

			ui.mouseCursorPosLabel->setText(ui.mouseCursorPosLabel->text() +
				QString(" [") + QString::number((int)(xScalingFactor*playerThread[index]->getCurrentROI().width())) +
				QString(",") + QString::number((int)(yScalingFactor*playerThread[index]->getCurrentROI().height())) +
				QString("]"));
		}
	}
}

void KETI_SERVER::newMouseDataOriginalFrame(struct MouseData mouseData)
{
	// Local variable(s)
	int x_temp, y_temp, width_temp, height_temp;
	QRect selectionBox;

	// Set ROI
	if (mouseData.leftButtonRelease)
	{
		double xScalingFactor;
		double yScalingFactor;
		double wScalingFactor;
		double hScalingFactor;

		// Selection box calculation depends on whether frame is scaled to fit label or not
		if (!originalFrame[index]->hasScaledContents())
		{
			xScalingFactor = ((double)mouseData.selectionBox.x() - ((originalFrame[index]->width() - originalFrame[index]->pixmap()->width()) / 2)) / (double)originalFrame[index]->pixmap()->width();
			yScalingFactor = ((double)mouseData.selectionBox.y() - ((originalFrame[index]->height() - originalFrame[index]->pixmap()->height()) / 2)) / (double)originalFrame[index]->pixmap()->height();
			wScalingFactor = (double)playerThread[index]->getCurrentROI().width() / (double)originalFrame[index]->pixmap()->width();
			hScalingFactor = (double)playerThread[index]->getCurrentROI().height() / (double)originalFrame[index]->pixmap()->height();
		}
		else
		{
			xScalingFactor = (double)mouseData.selectionBox.x() / (double)originalFrame[index]->width();
			yScalingFactor = (double)mouseData.selectionBox.y() / (double)originalFrame[index]->height();
			wScalingFactor = (double)playerThread[index]->getCurrentROI().width() / (double)originalFrame[index]->width();
			hScalingFactor = (double)playerThread[index]->getCurrentROI().height() / (double)originalFrame[index]->height();
		}

		// Set selection box properties (new ROI)
		selectionBox.setX(xScalingFactor*playerThread[index]->getCurrentROI().width() + playerThread[index]->getCurrentROI().x());
		selectionBox.setY(yScalingFactor*playerThread[index]->getCurrentROI().height() + playerThread[index]->getCurrentROI().y());
		selectionBox.setWidth(wScalingFactor*mouseData.selectionBox.width());
		selectionBox.setHeight(hScalingFactor*mouseData.selectionBox.height());

		// Check if selection box has NON-ZERO dimensions
		if ((selectionBox.width() != 0) && ((selectionBox.height()) != 0))
		{
			// Selection box can also be drawn from bottom-right to top-left corner
			if (selectionBox.width()<0)
			{
				x_temp = selectionBox.x();
				width_temp = selectionBox.width();
				selectionBox.setX(x_temp + selectionBox.width());
				selectionBox.setWidth(width_temp*-1);
			}
			if (selectionBox.height()<0)
			{
				y_temp = selectionBox.y();
				height_temp = selectionBox.height();
				selectionBox.setY(y_temp + selectionBox.height());
				selectionBox.setHeight(height_temp*-1);
			}

			// Check if selection box is not outside window
			if ((selectionBox.x()<0) || (selectionBox.y()<0) ||
				((selectionBox.x() + selectionBox.width())>(playerThread[index]->getCurrentROI().x() + playerThread[index]->getCurrentROI().width())) ||
				((selectionBox.y() + selectionBox.height())>(playerThread[index]->getCurrentROI().y() + playerThread[index]->getCurrentROI().height())) ||
				(selectionBox.x()<playerThread[index]->getCurrentROI().x()) ||
				(selectionBox.y()<playerThread[index]->getCurrentROI().y()))
			{
				// Display error message
				QMessageBox::warning(this, tr("ERROR:"), tr("Selection box outside range. Please try again."));
			}
			// Set ROI
			else
				emit setROI(selectionBox);
		}
	}
}

void KETI_SERVER::handleContextMenuAction(QAction *action)
{
	if (action->text() == "Reset ROI")
		emit setROI(QRect(0, 0, playerThread[index]->getInputSourceWidth(), playerThread[index]->getInputSourceHeight()));
	else if (action->text() == "Scale to Fit Frame") {
		ui.frameLabel_main->setScaledContents(action->isChecked());
		originalFrame[index]->setScaledContents(action->isChecked());
	}
	else if (action->text() == "Show Original Frame")
		handleOriginalWindow(action->isChecked());
}

void KETI_SERVER::handleOriginalWindow(bool doEmit)
{
	originalFrame[index]->setVisible(doEmit);
	playerThread[index]->getOriginalFrame(doEmit);
}

// Actions for Player by User Input
void KETI_SERVER::play()
{
	// Video is currently stopped or paused, so play and switch button for pausing
	if (playerThread[index]->isStopping() || playerThread[index]->isPausing()) {
		playerThread[index]->playAction();
		ui.PlayButton->setText(tr("Pause"));
	}
	// Video is currently beeing played, so pause it
	else if (playerThread[index]->isPlaying()) {
		pause();
	}
}

void KETI_SERVER::stop()
{
	ui.PlayButton->setText(tr("Play"));
	ui.TimeSlider->setValue(0);
	ui.currentTimeLabel->setText(getFormattedTime(0));
	playerThread[index]->stopAction();
}

void KETI_SERVER::pause()
{
	ui.PlayButton->setText(tr("Play"));
	playerThread[index]->pauseAction();
}

void KETI_SERVER::setTime()
{
	int val = ui.TimeSlider->value();
	playerThread[index]->setCurrentFrame(val);

	if (ui.PlayButton->text() == "Pause") {
		playerThread[index]->playAction();
	}
}

void KETI_SERVER::hideSettings()
{
	if (ui.tabWidget->isHidden()) {
		ui.tabWidget->show();
		ui.hideSettingsButton->setText("Hide Settings");
	}
	else {
		ui.tabWidget->hide();
		ui.hideSettingsButton->setText("Show Settings");
	}
}

void KETI_SERVER::save_action()
{
	if (vidSaver[index]->isSaving()) {
		vidSaver[index]->stop();
		return;
	}

	std::string source = file[index].absoluteFilePath().toStdString();
	QString userInput = QFileDialog::getSaveFileName(this,
		tr("Save Capture"),
		".",
		tr("Video File (*.avi *.mov *.mpeg *.mp4 *.m4v *.mkv)"));
	if (userInput.isEmpty()) {
		return;
	}
	std::string destination = userInput.toStdString();

	// First, load the file about to be processed
	if (vidSaver[index]->loadFile(source)) {
		// Second, hand over the Settings for magnification
		imageProcessingFlags = magnifyOptionsTab->getFlags();

		//Set Codec
		int savingCodec = (useVideoCodec) ? vidSaver[index]->getVideoCodec() : codec;
		vidSaver[index]->savingCodec = savingCodec;

		vidSaver[index]->settings(magnifyOptionsTab->getFlags(), magnifyOptionsTab->getSettings());
		// Third, start saving if destination is valid
		if (vidSaver[index]->saveFile(destination, playerThread[index]->getFPS(), playerThread[index]->getCurrentROI(), ui.saveOriginalCheckBox->checkState())) {
			// Show progressbar and set max value (= nr of frames of video)
			ui.saveProgressBar->show();
			ui.saveProgressBar->setMaximum(vidSaver[index]->getVideoLength());
			ui.saveButton->setText("Abort saving");
			ui.saveButton->setChecked(true);

			// Stop  player Thread to set memory free
			stop();
			// Lock controls
			//            ui.PlayButton->setEnabled(false);
			//            ui.StopButton->setEnabled(false);
			//            ui.TimeSlider->setEnabled(false);
			// start saving the video
			vidSaver[index]->start();
		}
		else
			QMessageBox::warning(this->parentWidget(), "WARNING:", "Please enter a valid filename and -ending or change Codec (File->Saving Codec)");
	}
	else
		QMessageBox::warning(this->parentWidget(), "WARNING:", "Not able to load video");
}

void KETI_SERVER::endOfSaving_action()
{
	ui.saveButton->setText("Save");
	ui.saveButton->setChecked(false);
	ui.saveProgressBar->setValue(0);
	ui.saveProgressBar->hide();

	// Unlock Controls
	//    ui.PlayButton->setEnabled(true);
	//    ui.StopButton->setEnabled(true);
	//    ui.TimeSlider->setEnabled(true);

}

void KETI_SERVER::updateProgressBar(int frame)
{
	ui.saveProgressBar->setValue(frame);
}

void KETI_SERVER::handleTabChange(int index)
{
	if (index == 1)
		ui.InfoTab->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
	else
		ui.InfoTab->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Ignored);
}

void KETI_SERVER::setCodec(int codec)
{
	this->codec = codec;
}

void KETI_SERVER::set_useVideoCodec(bool use)
{
	this->useVideoCodec = use;
}
