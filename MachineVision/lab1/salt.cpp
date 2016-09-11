#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

void salt(Mat &img, int n) {
	for (int k = 0; k < n; k++) {
		int i = rand() % img.cols;
		int j = rand() % img.rows;
		if (img.channels() == 1) {
			img.at<uchar>(j, i) = 255;
		} else if (img.channels() == 3) {
			for (int c = 0; c < 3; c++)
				img.at<Vec3b>(j, i)[0] = 255;
		}

	}

}

int main() {
    Mat img1 = imread("cat.jpg");
    Mat img2 = imread("cat.jpg");
    namedWindow("src");
    namedWindow("dst");
    salt(img2, 1000000);
    imshow("src", img1);
    imshow("dst", img2);
    imwrite("salt_cat.jpg", img2);
    waitKey(10000);
    return 0;
}
