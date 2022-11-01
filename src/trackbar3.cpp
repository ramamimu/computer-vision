#include <opencv2/core.hpp>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;

using std::cout;
using namespace std;

const int alpha_slider_max = 100;
int alpha_slider;
double alpha;
double beta;
Mat src1;
Mat src2;
Mat dst;

static void on_trackbar( int, void* )
{
   cout << alpha_slider << endl;
   alpha = (double) alpha_slider/alpha_slider_max ;
   beta = ( 1.0 - alpha );
   addWeighted( src1, alpha, src2, beta, 0.0, dst);
   imshow( "Linear Blend", dst );
}
int main( void )
{
   src1 = imread( "/home/ram/IRIS/OpenCV/image/img1.jpg") ;
   src2 = imread( "/home/ram/IRIS/OpenCV/image/img2.jpg") ;
   if( src1.empty() ) { cout << "Error loading src1 \n"; return -1; }
   if( src2.empty() ) { cout << "Error loading src2 \n"; return -1; }
   alpha_slider = 0;
   namedWindow("Linear Blend", WINDOW_AUTOSIZE); // Create Window
   char TrackbarName[50];
   snprintf( TrackbarName, sizeof(TrackbarName), "Alpha x %d", alpha_slider_max );
//    createTrackbar( TrackbarName, "Linear Blend", &alpha_slider, alpha_slider_max, on_trackbar );
   createTrackbar( TrackbarName, "Linear Blend", &alpha_slider, alpha_slider_max );
   on_trackbar( alpha_slider, 0 );
   // while(true){
      // cout << cv::getTrackbarPos(TrackbarName, "Linear Blend") << endl;
      // line(TrackbarName, cv::Point(0, 0), cv::Point(250, 250), cv::Scalar(255, 255, 255), 50);
   //    if (waitKey(30) >= 0)
   //       break;    

   // }
   return 0;
}