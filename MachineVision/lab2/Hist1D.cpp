#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
  
using namespace std;
using namespace cv;

int main(   )   
{  
    Mat gray_image, init;    
    Mat result;  
         
    init = imread("cat.jpg");      
    cvtColor(init, gray_image, CV_RGB2GRAY);
    int hbins = 256, sbins = 32;
    int histSize[] = {hbins, sbins};
    float hranges[] = {0, 180};
    float sranges[] = {0, 256};
    const float* ranges[] = {hranges, sranges};
    int channels[] = {0, 1};
    MatND hist;

    calcHist(
                &gray_image,
                1,
                channels,
                Mat(),
                hist,
                1,
                histSize,
                ranges
            );


    for (int i = 0; i < 256; i++) {
        cout << "Value " << i << " = " << hist.at<float>(i) << endl;
    }

    namedWindow("Result picture"); // define the window  
    imshow("Result picture", gray_image); // display the Flip gray_image  
      
    cv::waitKey(100000); // wait for key pressed  
} 
