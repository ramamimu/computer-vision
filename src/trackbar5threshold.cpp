#include <bits/stdc++.h>
#include <opencv2/opencv.hpp> 

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    Mat img, img_resized, img_hsv;
    img = imread("/home/ram/IRIS/OpenCV/image/img4.jpg");
    // resize(img, img_resized, Size(), 2, 2);
    int divided_scale = 10;
    resize(img, img_resized, Size(img.cols/divided_scale, img.rows/divided_scale));
    cvtColor(img_resized, img_hsv, COLOR_BGR2HSV);
    // resize(img_resized, img_resized, Size(img_resized.cols/divided_scale, img_resized.rows/divided_scale));

    int L_H = 0;
    int U_H = 77;
    int L_S = 73;
    int U_S = 247;
    int L_V = 83;
    int U_V = 228;
    namedWindow("threshold", WINDOW_AUTOSIZE);
    createTrackbar("L_H", "threshold", &L_H, 179);
    createTrackbar("U_H", "threshold", &U_H, 179);
    createTrackbar("L_S", "threshold", &L_S, 255);
    createTrackbar("U_S", "threshold", &U_S, 255);
    createTrackbar("L_V", "threshold", &L_H, 255);
    createTrackbar("U_V", "threshold", &U_V, 255);
    while (true)
    {
        /* code */
    inRange(img_resized, Scalar(L_H, L_S, L_V), Scalar(U_H, U_S, U_V), img_hsv);
    imshow("WINDOW", img_hsv);
    imshow("WINDOW img", img_resized);
    if(waitKey(30) > 0)
        break;
    
    }
    

    // waitKey(0);

    return 0;
}