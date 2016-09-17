#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

/**  @function main */
int main( int argc, char** argv )
{
  Mat src, dst;

  string source_window = "Source image";
  string equalized_window = "Equalized Image";
  /// Load image
  src = imread( "cat.jpg", 1 );
  /// Convert to grayscale
  cvtColor( src, src, CV_BGR2GRAY );
  /// Apply Histogram Equalization
  equalizeHist( src, dst );
  /// Display results
  namedWindow( source_window, CV_WINDOW_AUTOSIZE );
  namedWindow( equalized_window, CV_WINDOW_AUTOSIZE );

  imshow( source_window, src );
  imshow( equalized_window, dst );

  /// Wait until user exits the program
  waitKey(0);

  return 0;
}
