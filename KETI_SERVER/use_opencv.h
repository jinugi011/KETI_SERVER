#pragma once

#include "opencv/highgui.h"
#include "opencv2/imgproc/imgproc.hpp"

#include "opencv2/core/core.hpp"
#include "opencv2/core/core_c.h"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/video/video.hpp"
#include "opencv2/imgcodecs.hpp"



#ifdef _DEBUG
#pragma comment(lib,"opencv_core320d.lib")
#pragma comment(lib,"opencv_highgui320d.lib")
#pragma comment(lib,"opencv_imgproc320d.lib")
//	#pragma comment(lib,"opencv_video320d.lib")
//	#pragma comment(lib,"opencv_nonfree320d.lib")
//	#pragma comment(lib,"opencv_videostab320d.lib")
//	#pragma comment(lib,"opencv_features2d320d.lib")
//	#pragma comment(lib,"opencv_objdetect320d.lib")
//	#pragma comment(lib,"opencv_flann320d.lib")
//	#pragma comment(lib,"opencv_photo320d.lib")
//	#pragma comment(lib,"opencv_calib3d320d.lib")
//	#pragma comment(lib,"opencv_ml320d.lib")
//	#pragma comment(lib,"opencv_contrib320d.lib")
//	#pragma comment(lib,"opencv_ts320d.lib")
//	#pragma comment(lib,"opencv_stitching320d.lib")
//	#pragma comment(lib,"opencv_legacy320d.lib")
#else
#pragma comment(lib,"opencv_core320.lib")
#pragma comment(lib,"opencv_highgui320.lib")
#pragma comment(lib,"opencv_imgproc320.lib")
#pragma comment(lib,"opencv_imgcodecs320.lib")
#pragma comment(lib,"opencv_video320.lib")
#pragma comment(lib,"opencv_videoio320.lib")
#pragma comment(lib,"opencv_aruco320.lib")
#pragma comment(lib,"opencv_bgsegm320.lib")
#pragma comment(lib,"opencv_bioinspired320.lib")
#pragma comment(lib,"opencv_calib3d320.lib")
#pragma comment(lib,"opencv_ccalib320.lib")
#pragma comment(lib,"opencv_datasets320.lib")
#pragma comment(lib,"opencv_dnn320.lib")
#pragma comment(lib,"opencv_dpm320.lib")
#pragma comment(lib,"opencv_stitching320.lib")

//#pragma comment(lib,"KETI_SERVER.lib")


#endif

template<class T>
class TypedMat
{
	T** m_pData;
	int m_nChannels;
	int m_nRows, m_nCols;

public:
	TypedMat() :m_pData(NULL), m_nChannels(1), m_nRows(0), m_nCols(0) {}
	~TypedMat() { if (m_pData) delete[] m_pData; }

	// OpenCV Mat ���� (�޸� ����)
	void Attach(const cv::Mat& m);
	void Attach(const IplImage& m);
	TypedMat(const cv::Mat& m) :m_pData(NULL), m_nChannels(1), m_nRows(0), m_nCols(0) { Attach(m); }
	TypedMat(const IplImage& m) :m_pData(NULL), m_nChannels(1), m_nRows(0), m_nCols(0) { Attach(m); }
	const TypedMat & operator =(const cv::Mat& m) { Attach(m); return *this; }
	const TypedMat & operator =(const IplImage& m) { Attach(m); return *this; }

	// ��(row) ��ȯ
	T* GetPtr(int r)
	{
		assert(r >= 0 && r<m_nRows); return m_pData[r];
	}

	// ������ ��ø (��������) -- 2D
	T * operator [](int r)
	{
		assert(r >= 0 && r<m_nRows); return m_pData[r];
	}

	const T * operator [](int r) const
	{
		assert(r >= 0 && r<m_nRows); return m_pData[r];
	}

	// ������ ��ø (��������) -- 3D
	T & operator ()(int r, int c, int k)
	{
		assert(r >= 0 && r<m_nRows && c >= 0 && c<m_nCols && k >= 0 && k<m_nChannels); return m_pData[r][c*m_nChannels + k];
	}

	const T operator ()(int r, int c, int k) const
	{
		assert(r >= 0 && r<m_nRows && c >= 0 && c<m_nCols && k >= 0 && k<m_nChannels); return m_pData[r][c*m_nChannels + k];
	}
};

template<class T>
void TypedMat<T>::Attach(const cv::Mat& m)
{
	assert(sizeof(T) == m.elemSize1());

	m_nChannels = m.channels();
	m_nRows = m.rows;
	m_nCols = m.cols;

	if (m_pData) delete[] m_pData;
	m_pData = new T *[m_nRows];
	for (int r = 0; r<m_nRows; r++)
	{
		m_pData[r] = (T *)(m.data + r*m.step);
	}
}

template<class T>
void TypedMat<T>::Attach(const IplImage& m)
{
	assert(sizeof(T) == m.widthStep / (m.width*m.nChannels));

	m_nChannels = m.nChannels;
	m_nRows = m.height;
	m_nCols = m.width;

	if (m_pData) delete[] m_pData;
	m_pData = new T *[m_nRows];
	for (int r = 0; r<m_nRows; r++)
	{
		m_pData[r] = (T *)(m.imageData + r*m.widthStep);
	}
}
