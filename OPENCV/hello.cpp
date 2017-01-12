
#include <cv.h>

#include <highgui.h>

using namespace std;

int amain()

{

	IplImage * test;

	test = cvLoadImage("E:\\_DSC6968.jpg");//Í¼Æ¬Â·¾¶

	cvNamedWindow("test_demo", 1);

	cvShowImage("test_demo", test);

	cvWaitKey(0);

	cvDestroyWindow("test_demo");

	cvReleaseImage(&test);

	return 0;

}