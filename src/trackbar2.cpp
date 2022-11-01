
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

#include <opencv2/core.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using std::cout;
const int alpha_slider_max = 100;
int alpha_slider;
double alpha;
double beta;
Mat src1;
Mat src2;
Mat dst;


static void on_trackbar( int, void* )
{
   alpha = (double) alpha_slider/alpha_slider_max ;
   beta = ( 1.0 - alpha );
   addWeighted( src1, alpha, src2, beta, 0.0, dst);
   imshow( "Linear Blend", dst );
}
int main( void )
{
   src1 = imread( "/home/ram/IRIS/OpenCV/image/img1.jpg" );
   src2 = imread( "/home/ram/IRIS/OpenCV/image/img2.jpg" );
    int divided_scale = 6;

    resize(src1, src1, Size(src1.cols/divided_scale, src1.rows/divided_scale));
    resize(src2, src2, Size(src2.cols/divided_scale, src2.rows/divided_scale));
   
    imshow("src1",src1);
    imshow("src2",src2);
    
   char TrackbarName[50];
   sprintf( TrackbarName, "Alpha x %d", alpha_slider_max );
     createTrackbar( TrackbarName, "Linear Blend", &alpha_slider, alpha_slider_max, on_trackbar );


//    if( src1.empty() ) { cout << "Error loading src1 \n"; return -1; }
//    if( src2.empty() ) { cout << "Error loading src2 \n"; return -1; }
//    alpha_slider = 0;
//    namedWindow("Linear Blend", WINDOW_AUTOSIZE); // Create Window
//    char TrackbarName[50];
//    sprintf( TrackbarName, "Alpha x %d", alpha_slider_max );
//    createTrackbar( TrackbarName, "Linear Blend", &alpha_slider, alpha_slider_max, on_trackbar );
//    on_trackbar( alpha_slider, 0 );
   waitKey(0);
   return 0;
}