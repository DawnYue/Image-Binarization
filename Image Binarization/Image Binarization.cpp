#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>

using namespace cv;
using namespace std;


string window_name = "binaryMat";
int main()
{  
	Mat srcMat;
	Mat gryMat;
	int lowTh = 30;
	int maxTh = 255;
	cv::Mat srcMat = imread("E:\\4.png");

	//创建滑动条来控制阈值
	createTrackbar("模式",
		WINDOW_NAME, &g_nThresholdType,
		4, on_Threshold);

	VideoCapture cap(0);
	double scale=0.5;
	//0-180肤色
	double i_minH = 0;
	double i_maxH = 20;
	//0-255
	double i_minS = 43;
	double i_maxS = 255;
	//0-255
	double i_minV = 55;
	double i_maxV = 255;

	while (1)
	{   
		Mat frame;
		Mat hsvMat;
		Mat detectMat;

		cap >> frame;
		Size ResImgSiz = Size(frame.cols*scale, frame.rows*scale);
		Mat rFrame = Mat(ResImgSiz, frame.type());
		resize(frame, rFrame, ResImgSiz, INTER_LINEAR);
		
		threshold(frame, rFrame, 100, 255, THRESH_BINARY);//阈值函数
		adaptiveThreshold(frame, rFrame,255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV,15,0);//区域自适应二值化
		
		cvtColor(rFrame, hsvMat, COLOR_BGR2HSV);

		rFrame.copyTo(detectMat);
		cv::inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), detectMat);
		imshow("while :in the range", detectMat);
		imshow("frame", rFrame);
		waitKey(30);
	}


}
