#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

int main() {
    Mat img1 = imread("cat.jpg");
    Mat img2;
    namedWindow("src");
    namedWindow("dst");
    flip(img1, img2, 1);
    imshow("src", img1);
    imshow("dst", img2);
    imwrite("flipped_cat.jpg", img2);
    waitKey(10000);
    return 0;
}
