#include <bits/stdc++.h>
#include <opencv2/opencv.hpp> 

using namespace std;
using namespace cv;

Mat img, img_resized, img_hsv, img_hsv2, bw_and;
Mat HSV;

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
    if  ( event == EVENT_LBUTTONDOWN )
    {
        cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
        Vec3b hsv=img_hsv2.at<Vec3b>(y,x);
        int H=hsv.val[0];
        int S=hsv.val[1];
        int V=hsv.val[2];
        cout << "H = " << H << endl;
        cout << "S = " << S << endl;
        cout << "V = " << V << endl;

    }

    //  else if  ( event == EVENT_RBUTTONDOWN )
    //  {
    //       cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    //  }
    //  else 
    //  if  ( event == EVENT_MBUTTONDOWN )
    //  {
    //       cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    //  }
    //  else if ( event == EVENT_MOUSEMOVE )
    //  {
    //       cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;

    //  }
}

int main(int argc, char** argv) {

    img = imread("/home/ram/IRIS/OpenCV/image/img5.jpg");
    HSV = imread("/home/ram/IRIS/OpenCV/image/HSV.png");

    // resize(img, img_resized, Size(), 2, 2);
    int divided_scale = 8;
    resize(HSV, HSV, Size(), 2, 2);
    resize(img, img_resized, Size(img.cols/divided_scale, img.rows/divided_scale));
    cvtColor(img_resized, img_hsv, COLOR_BGR2HSV);
    cvtColor(img_resized, img_hsv2, COLOR_BGR2HSV);

    // cvtColor(img_resized, img_resized, COLOR_BGR2HSV);
    // cout << img_hsv.size() << endl;
    // resize(img_resized, img_resized, Size(img_resized.cols/divided_scale, img_resized.rows/divided_scale));

    // int L_H = 0;
    // int U_H = 77;
    // int L_S = 73;
    // int U_S = 247;
    // int L_V = 83;
    // int U_V = 228;
    int L_H = 0;
    int U_H = 180;
    int L_S = 0;
    int U_S = 255;
    int L_V = 0;
    int U_V = 255;
    namedWindow("threshold", WINDOW_AUTOSIZE);
    createTrackbar("L_H", "threshold", &L_H, 180);
    createTrackbar("U_H", "threshold", &U_H, 180);
    createTrackbar("L_S", "threshold", &L_S, 255);
    createTrackbar("U_S", "threshold", &U_S, 255);
    createTrackbar("L_V", "threshold", &L_V, 255);
    createTrackbar("U_V", "threshold", &U_V, 255);
    while (true)
    {
        Mat res;
        // res = Scalar(0,0,0);
        /* code */
        inRange(img_resized, Scalar(L_H, L_S, L_V), Scalar(U_H, U_S, U_V), img_hsv);
        bitwise_and(img_resized, img_resized,res, img_hsv);
        imshow("result", res);
        imshow("WINDOW HSV", img_hsv);
        imshow("HSV 2", img_hsv2);
        imshow("WINDOW img", img_resized);
        setMouseCallback("HSV 2", CallBackFunc, NULL);
        imshow("range HSV", HSV);

        // cout<<Scalar(L_H, L_S, L_V)<<endl;
        // cout<<Scalar(U_H, U_S, U_V)<<endl;
        //  Vec3b _hsv_ =  img_resized.at<Vec3b>(180,80);
        //  int H = _hsv_.val[0];
        //  cout << H << endl;
  
    // 180 300
    if(waitKey(30) > 0)
        break;
    }
    // waitKey(0);
    return 0;
}