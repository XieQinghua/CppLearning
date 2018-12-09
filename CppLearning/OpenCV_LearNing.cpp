#include"OpenCV_LearNing.h"

void test_capture()
{
	VideoCapture capture(0);
	if (!capture.isOpened()) {
		cout << "open camera failed!" << endl;
	}
	else {
		Mat frame;
		int index = 300;
		while (index--) {
			capture >> frame;
			imshow("VIDEO", frame);
			waitKey(1000 / 30);
		}
		destroyAllWindows();
	}

}

void image_gradient()
{

}
