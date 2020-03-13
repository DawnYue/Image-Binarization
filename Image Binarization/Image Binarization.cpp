#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;

int main()
{  
	cv::Mat src = imread("E:\\4.png");
	Mat srcMat;
	Mat dstMat1;
	Mat dstMat2;
	//原图的灰度图
	cvtColor(src, srcMat, COLOR_RGB2GRAY);

    threshold(srcMat, dstMat1, 100, 255, THRESH_BINARY);//阈值函数
	adaptiveThreshold(srcMat, dstMat2,255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV,15,0);//区域自适应二值化

	imshow("Image", dstMat1);
	waitKey(0);//等待用户按键

	imshow("Image", dstMat2);
	waitKey(0);//等待用户按键

	return 0;

}
