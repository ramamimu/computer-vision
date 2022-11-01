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

int main()
{
    cv::Mat img = cv::imread("/home/ram/IRIS/OpenCV/src/image1.png", IMREAD_UNCHANGED);
    cout << img.rows << endl;
    cout << img.cols << endl;
    // cv::Mat img = cv::imread("./image1.png", IMREAD_UNCHANGED);
    // cv::VideoCapture cap("chaplin.mp4");
    // cv::imshow("window", img);
    
    // cout << img << endl;

//    alpha_slider = 0;

//    char TrackbarName[50];
//    sprintf( TrackbarName, "Alpha x %d", alpha_slider_max );
//    createTrackbar( TrackbarName, "Linear Blend", &alpha_slider, alpha_slider_max, on_trackbar );
//    on_trackbar( alpha_slider, 0 );
    Mat image;

    cv::namedWindow("Display window");

    // cv::VideoCapture cap("/dev/v4l/by-id/usb-046d_C922_Pro_Stream_Webcam_70F3B3DF-video-index0");
    cv::VideoCapture cap(0);
    // cv::VideoCapture cap("/dev/v4l/by-id/usb-046d_C922_Pro_Stream_Webcam_70F3B3DF-video-index0 ! videoscale ! videorate ! video/x-raw, width=640, height=360, framerate=30/1 ! videoconvert ! appsink");    
    // cv::VideoCapture cap("/dev/video2");

    // cap.set(CAP_PROP_FOURCC, VideoWriter::fourcc('M', 'J', 'P', 'G'));

    // cv::VideoCapture cap("/dev/v4l/by-id/usb-SunplusIT_Inc_HD_User_Facing-video-index1");
    // cv::VideoCapture cap(1);

    while (true)
    {
        cap >> image;
        // cout << image << endl;
        cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
        cv::line(image, cv::Point(0, 0), cv::Point(250, 250), cv::Scalar(255, 255, 255), 50);
        cv::arrowedLine(image, cv::Point(0, 0), cv::Point(200, 300), cv::Scalar(255, 0, 0), 50);
        // cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
        cv::imshow("Display window", image);
        if (waitKey(30) >= 0)
            break;    
    }
    cv::destroyAllWindows();
        // waitKey(0); 
    return 0;
    // std::string image_path = samples::findFile("/home/ram/IRIS/OpenCV/src/image1.png", IMREAD_COLOR);
    // Mat img = imread(image_path, IMREAD_COLOR);
    // if(img.empty())
    // {
    //     std::cout << "Could not read the image: " << image_path << std::endl;
    //     return 1;
    // }
    // imshow("Display window", img);
    // int k = waitKey(0); // Wait for a keystroke in the window
    // if(k == 's')
    // {
    //     imwrite("starry_night.png", img);
    // }
    // return 0;
}

