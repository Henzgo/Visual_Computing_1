// Face_detector.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Face_detector.h"

using namespace std;
using namespace cv;

void detectAndDraw(Mat& img, CascadeClassifier& cascade, CascadeClassifier& nestedCascade, double scale);
string cascadeName, nestedCascadeName;

int main(int argc, const char** argv)
{
	VideoCapture capture;
	Mat frame, image;

	CascadeClassifier cascade, nestedCascade;
	double scale = 1;
	nestedCascade.load("resources/haarcascade_eye_tree_eyeglasses.xml");
	nestedCascade.load("resources/haarcascade_frontalface_default.xml");

	capture.open(0);
	if (capture.isOpened()) {
		std::cout << "Face Detection Started..." << std::endl;
		while (1) {
			capture frame;
			if (frame.empty())
				break;
			Mat frame1 = frame.clone();
			detectAndDraw(frame1, cascade, nestedCascade, scale);
			char c = (char)waitKey(10);

			if (c == 27 || c == 'q' || c == 'Q')
				break;
		}
	}
	else
		std::cout << "Could not open Camera" << std::endl;
	return 0;
}

void detectAndDraw(Mat img, CascadeClassifier cascade, CascadeClassifier nestedCascade, double scale) {
	vector Rect, faces, faces2;
	Mat gray, smallImg;

	cvtColor(img, gray, COLOR_BGR2GRAY);
	double fx = 1 / scale;

	resize(gray, smallImg, Size(), fx, fx, INTERN_LINEAR);
	equalizeHist(smallImg, smallImg);

	cascade.detectMultiScale(smallImg, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

	for (size_t i = 0; i < faces.size(); i++) {
		Rect rand = faces[i];
	})
}