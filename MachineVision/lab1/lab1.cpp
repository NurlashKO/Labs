#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>  
  
int main(   )   
{  
    cv::Mat image;  // create image  
        cv::Mat result;  
         
        image = cv::imread("monument.jpg");    // open image  
  
    // check if image has been successfully read  
    if (!image.data)    return 0;  
  
    cv:: cv::flip(image,result,1);  
    cv::namedWindow("Flip Image"); // define the window  
        cv::imshow("Flip Image", result); // display the Flip image  
      
    cv::waitKey(0); // wait for key pressed  
} 
