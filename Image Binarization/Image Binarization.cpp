#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>

using namespace cv;
using namespace std;


string window_name = "binaryMat";
void threshold_Mat(int th, void*data)
{
	Mat src= *(Mat*)(data);
	Mat dst;

	threshold(src, dst, th, 255, 0);

	imshow(window_name, dst);
}
/*

CV_EXPORTS int createTrackbar(const String& trackbarname, const String& winname,
	int* value, int count,
	TrackbarCallback onChange = 0,
	void* userdata = 0);
*/

int main()
{  
	Mat srcMat;
	Mat gryMat;
	int lowTh = 30;
	int maxTh = 255;
	srcMat = imread("E:\\4.png");
	if (!srcMat.data) 
	{ 
		cout << "打开失败" << endl; return 0; 
	}

	//原图的灰度图
	cvtColor(srcMat, gryMat, COLOR_RGB2GRAY);

	
	imshow(window_name, gryMat);
	createTrackbar("threshold",
		window_name,
		&lowTh, 
		maxTh, 
		threshold_Mat,
		&gryMat);
	waitKey(0);//等待用户按键

	return 0;

}
