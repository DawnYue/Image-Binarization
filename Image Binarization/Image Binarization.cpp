﻿#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat src_colar = imread("E:\\4.png");
	std::vector<cv::Mat>channels;
	Mat  dst;
	//转换成灰度图像，使原图成为单通道图像,或imread（"",0）;
	cvtColor(src_colar, dst, CV_BGR2GRAY);
	//查看图像通道数
	int c = dst.channels();
	cout << "=" << endl << c << endl;

	float histgram[256] = { 0 };
	for (int j = 0; j < dst.rows; j++) {
		uchar* row_ptr = dst.ptr <uchar>(j);// 第j行的头指针
		for (int i = 0; i < dst.cols; i++) {
			// 访问位于 x,y 处的像素
			uchar* data_ptr = &row_ptr[i*dst.channels()]; // data_ptr 指向待访问的像素数据
			// 输出该像素的每个通道,如果是灰度图就只有一个通道
			for (int c = 0; c != dst.channels(); c++)
			{
				uchar data = data_ptr[c]; // data为I(x,y)第c个通道的值	
				histgram[data] = histgram[data] + 1;//遍历像素
			}
		}
	}
	/*   遍历
	 for (int j = 0; j < dst.rows; j++) {
		 uchar* data = dst.ptr <uchar>(j);// 第j行的头指针
		 for (int i = 0; i < dst.cols; i++) {
			 //data[i] = j;   //I(x,y)像素
			 histgram[data[i]] = histgram[data[i]] + 1;
		 }//								   */

	float total;
	total = dst.rows*dst.cols;
	for (int i = 0; i < 256; i++) {
		histgram[i] = histgram[i] / total;
		cout << "histgram" << histgram[i] << endl;
	}

	int hist_h = 400;//直方图的图像的高
	int hist_w = 512;////直方图的图像的宽
	Mat histImage(hist_w, hist_h, CV_8UC3, Scalar(0, 0, 0));//绘制直方图显示的图像

	/*draw rectangle
	cv::Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.width = 2;
	for (int i = 0; i < 256; i++) {
		rect.x = rect.x + 2;
		rect.height = histgram[i]*28000;
		rectangle(histImage, rect, CV_RGB(255, 0, 0), 1, 8, 0);
	}//            */

	//*draw line
	Point pt1, pt2;
	pt1.x = 0;
	pt1.y = 399;
	pt2.x = 0;
	pt2.y = 0;
	for (int i = 0; i < 256; i++) {
		pt2.y = pt1.y - histgram[i] * 20000;

		pt2.x = pt2.x + 1;
		pt1.x = pt2.x;
		line(histImage, pt1, pt2, CV_RGB(255, 0, 0), 1, 8, 0);
		pt2.x = pt2.x + 1;
		pt1.x = pt2.x;
		line(histImage, pt1, pt2, CV_RGB(255, 0, 0), 1, 8, 0);

	}//							*/


	imshow("histImage", histImage);
	waitKey(0);//等待用户按键
	return 0;
}