#include <opencv2/core.hpp>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

const int alpha_slider_max = 100;
int alpha_slider;
double alpha;
double beta;

Mat img;

static void on_trackbar( int, void* )
{
   alpha = (double) alpha_slider/alpha_slider_max ;
   beta = ( 1.0 - alpha );
   addWeighted( img, alpha, img, beta, 0.0, img);
   imshow( "Linear Blend", img );
}


int main(){
    img = imread("/home/ram/IRIS/OpenCV/image/img1.jpg");
    // img.resize(img.rows/4, img.cols/4);
    int divided_scale = 6;
    resize(img, img, Size(img.cols/divided_scale, img.rows/divided_scale));
   alpha_slider = 0;

   namedWindow("Linear Blend", WINDOW_AUTOSIZE); // Create Window
   char TrackbarName[50];
   sprintf( TrackbarName, "Alpha x %d", alpha_slider_max );
   createTrackbar( TrackbarName, "Linear Blend", &alpha_slider, alpha_slider_max );
   on_trackbar( alpha_slider, 0 );
 
    // imshow("image", img);
    waitKey(0);
    return 0;
}