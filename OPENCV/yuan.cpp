#include "opencv2/core/core.hpp"  
#include "opencv2/highgui/highgui.hpp"  
#include "opencv2/imgproc/imgproc.hpp"  

#include <iostream>  
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src, gray;
	src = imread("E:\\125.jpg");
	if (!src.data)
		return -1;

	cvtColor(src, gray, CV_BGR2GRAY);
	//高斯模糊平滑  
	GaussianBlur(gray, gray, Size(9, 9), 2, 2);

	vector<Vec3f> circles;
	//霍夫变换  
	HoughCircles(gray, circles, CV_HOUGH_GRADIENT, 1, gray.rows / 20, 100, 60, 0, 0);

	//在原图中画出圆心和圆  
	for (size_t i = 0; i < circles.size(); i++)
	{
		//提取出圆心坐标  
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		//提取出圆半径  
		int radius = cvRound(circles[i][2]);
		//圆心  
		circle(src, center, 3, Scalar(0, 255, 0), -1, 8, 0);
		//圆  
		circle(src, center, radius, Scalar(0, 0, 255), 3, 8, 0);
	}

	namedWindow("Circle", CV_WINDOW_AUTOSIZE);
	imshow("Circle", src);

	waitKey(0);
	return 0;
}