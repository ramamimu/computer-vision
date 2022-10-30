#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
// #include <iostream>
using namespace cv;
int main()
{
    // cv::Mat img = cv::imread("/home/ram/IRIS/OpenCV/src/image1.png");
    // cv::VideoCapture cap("chaplin.mp4");
    // cv::imshow("window", img);
    Mat image;

    cv::namedWindow("Display window");

    cv::VideoCapture cap(0);

    while (true)
    {
        cap >> image;
        cv::imshow("Display window", image);
        if (waitKey(1) >= 0)
            break;    
        // waitKey(1);
    }
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

