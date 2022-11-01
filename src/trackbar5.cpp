#include <bits/stdc++.h>
#include <opencv2/opencv.hpp> 

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    Mat img, img_resized, img_hsv;
    img = imread("/home/ram/IRIS/OpenCV/image/img2.jpg");
    resize(img, img_resized, Size(), 2, 2);
    cvtColor(img_resized, img_hsv, COLOR_BGR2HSV);

    int L_H = 0;
    int U_H = 77;
    int L_S = 73;
    int U_S = 247;
    int L_V = 83;
    int U_V = 228;
    namedWindow("threshold", WINDOW_AUTOSIZE);
    createTrackbar("L_H", "threshold", nullptr, 179);
    createTrackbar("U_H", "threshold", nullptr, 179);
    createTrackbar("L_S", "threshold", nullptr, 255);
    createTrackbar("U_S", "threshold", nullptr, 255);
    createTrackbar("L_V", "threshold", nullptr, 255);
    createTrackbar("L_V", "threshold", nullptr, 255);
    setTrackbarPos("L_H", "threshold", L_H);
    setTrackbarPos("U_H", "threshold", U_H);
    setTrackbarPos("L_S", "threshold", L_S);
    setTrackbarPos("U_S", "threshold", U_S);
    setTrackbarPos("L_V", "threshold", L_V);
    setTrackbarPos("U_V", "threshold", U_V);
    while (true) {
        L_H = getTrackbarPos("L_H", "threshold");
        U_H = getTrackbarPos("U_H", "threshold");
        L_S = getTrackbarPos("L_S", "threshold");
        U_S = getTrackbarPos("U_S", "threshold");
        L_V = getTrackbarPos("L_V", "threshold");
        U_V = getTrackbarPos("U_V", "threshold");
        Mat img_threshold;
        inRange(img_hsv, Scalar(L_H, L_S, L_V), Scalar(U_H, U_S, U_V), img_threshold);
        imshow("threshold", img_threshold);
        if (waitKey(1) == 27) {
            break;
        }
    }
    // while (true)
    // {
    //     /* code */
    // // inRange(img, Scalar(L_H, L_S, L_V), Scalar(U_H, U_S, U_V), img_hsv);
    // imshow("WINDOW", img_hsv);
    // imshow("WINDOW img", img);
    // if(waitKey(0) >= 0)
    //     break;
    
    // }
    

    // waitKey(0);

    return 0;
}