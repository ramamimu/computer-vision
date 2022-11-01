
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

#include <opencv2/core.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;
const int alpha_slider_max = 100;
int alpha_slider;

int lh = 0;
int ls = 0;
int lv = 0;
int uh;
int us;
int uv;

double alpha;
double beta;
Mat src1;
Mat src2;
Mat dst;
Mat bw_and;
Mat bw_or;
Mat bw_xor;

Mat hsv;

static void on_trackbar( int, void* )
{
   alpha = (double) alpha_slider/alpha_slider_max ;
   cout <<"alpha = "<< alpha << endl;
   cout <<"lh = " << lh << endl;
   cout <<"ls = " << ls << endl;
   cout <<"lv = " << lv << endl;
   cout <<"uh = " << uh << endl;
   cout <<"us = " << us << endl;
   cout <<"uv = " << uv << endl;
   beta = ( 1.0 - alpha );
   addWeighted( src1, alpha, src2, beta, 0.0, dst);
   imshow( "Linear Blend", dst );
   
   // hsv=src2.clone();
   
   // cvtColor(src2, hsv, COLOR_BGR2HSV);
   // inRange(hsv, Scalar(lh, ls, lv), Scalar(uh, us, uv), hsv);
   // imshow("hsv", hsv);

   bitwise_and(src2, src2, bw_and, hsv);
   bitwise_or(src1, src2, bw_or);
   bitwise_xor(src1, src2, bw_xor);
   // bitwise_and(src1, src2, bw_and);
   imshow("Bitwise AND", bw_and);
   imshow("Bitwise OR", bw_or);
   imshow("Bitwise XOR", bw_xor);
}
int main( void )
{
   src1 = imread( "/home/ram/IRIS/OpenCV/image/img3.jpg" );
   src2 = imread( "/home/ram/IRIS/OpenCV/image/img2.jpg" );
   int divided_scale = 6;

   resize(src1, src1, Size(src1.cols/divided_scale, src1.rows/divided_scale));
   resize(src2, src2, Size(src2.cols/divided_scale, src2.rows/divided_scale));
   
   imshow("src1",src1);
   imshow("src2",src2);
    
   alpha_slider = 0;

   namedWindow("Linear Blend", WINDOW_AUTOSIZE); // Create Window
   // namedWindow("regreso", WINDOW_AUTOSIZE); // Create Window


   char TrackbarName[50];
   sprintf( TrackbarName, "Alpha x %d", alpha_slider_max );
   createTrackbar( TrackbarName, "Linear Blend", &alpha_slider, alpha_slider_max, on_trackbar );

   createTrackbar("lh", "Linear Blend", &lh, 255, on_trackbar);
   createTrackbar("ls", "Linear Blend", &ls, 255, on_trackbar);
   createTrackbar("lv", "Linear Blend", &lv, 255, on_trackbar);
   createTrackbar("uh", "Linear Blend", &uh, 255, on_trackbar);
   createTrackbar("us", "Linear Blend", &us, 255, on_trackbar);
   createTrackbar("uv", "Linear Blend", &uv, 255, on_trackbar);


   on_trackbar( alpha_slider, 0 );

   while (true)
   {
      cvtColor(src2, hsv, COLOR_BGR2HSV);
      inRange(hsv, Scalar(lh, ls, lv), Scalar(uh, us, uv), hsv);
      imshow("hsv", hsv);
      if(waitKey(30) >= 0) break;
      /* code */
   }
   

   waitKey(0);
   return 0;
}