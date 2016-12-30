#include "KETI_SERVER.h"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

KETI_SERVER::KETI_SERVER(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//이벤트 처리 
	//InitMain();

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

	IplImage *image;

	image = cvLoadImage("./test.jpg");
	//cvNamedWindow("YANG JIN", CV_WINDOW_AUTOSIZE);
	cvShowImage("YANG JIN", image);
	cvReleaseImage(&image);


	//cvvShowImage("YANG JIN", image);

}