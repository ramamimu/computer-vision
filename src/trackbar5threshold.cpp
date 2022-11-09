#include <bits/stdc++.h>
#include <opencv2/opencv.hpp> 

using namespace std;
using namespace cv;

Mat img, img_resized, img_hsv, img_hsv2, bw_and;
Mat HSV, gaussian_blur, canny_filter;

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
}

int main(int argc, char** argv) {

    VideoCapture cap(0);

    int L_H = 0;
    int U_H = 180;
    int L_S = 0;
    int U_S = 255;
    int L_V = 0;
    int U_V = 255;
    namedWindow("threshold", WINDOW_AUTOSIZE);
    createTrackbar("L_H", "threshold", &L_H, 255);
    createTrackbar("U_H", "threshold", &U_H, 255);
    createTrackbar("L_S", "threshold", &L_S, 255);
    createTrackbar("U_S", "threshold", &U_S, 255);
    createTrackbar("L_V", "threshold", &L_V, 255);
    createTrackbar("U_V", "threshold", &U_V, 255);
    vector<Point2f> mc_vector;
    // bool flag = false;
    bool flag = true;
    while (true)
    {
        cap >> img;
        flip(img, img, 1);
        // img = imread("/home/ram/IRIS/OpenCV/image/img5.jpg");
        HSV = imread("/home/ram/IRIS/OpenCV/image/HSV.png");

        // resize(img, img_resized, Size(), 2, 2);
        int divided_scale = 8;
        resize(HSV, HSV, Size(), 2, 2);
        resize(img, img_resized, Size(), .5, .5);
        GaussianBlur(img_resized, gaussian_blur, Size(5, 5), 0, 0);
        cvtColor(gaussian_blur, img_hsv, COLOR_BGR2HSV);
        cvtColor(gaussian_blur, img_hsv2, COLOR_BGR2HSV);
        // Canny(gaussian_blur, canny_filter, 50, 150, 3);

        // image filtering
        Mat res, final_contours;
        vector<vector<Point> > contours;
        final_contours = img_resized.clone();
        inRange(img_resized, Scalar(L_H, L_S, L_V), Scalar(U_H, U_S, U_V), img_hsv);
        bitwise_and(img_resized, img_resized,res, img_hsv);
        setMouseCallback("HSV 2", CallBackFunc, NULL);
        findContours( img_hsv, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE );
        uint32_t max_contour = 0;
        int32_t max_contour_index = -1;
        Moments mu;
        for (int i = 0; i<contours.size(); i++)
        {
            // drawContours(final_contours, contours, i, Scalar(0, 250, 0), 3);
            // cout << contourArea(contours[i]) << endl;
            if(contourArea(contours[i]) > max_contour)
            {
                max_contour = contourArea(contours[i]);
                max_contour_index = i;
                mu = moments( contours[i] );
            }
        }
        Point2f mc;
        if(max_contour_index != -1)
        {
            mc = Point2f( mu.m10/mu.m00 , mu.m01/mu.m00 );
            cout << "center point " << mc << endl;
            drawContours(final_contours, contours, max_contour_index, Scalar(0, 0, 250), 3);
            circle(final_contours, mc, 4, Scalar(250, 0, 0), -1, 8, 0);
            // resize(final_contours, final_contours, Size(), 1.5, 1.5);
            if(flag)
                mc_vector.push_back(mc);
            if(mc_vector.size() >= 20)
                mc_vector.erase(mc_vector.begin());
        }

        if(mc_vector.size() != 0 ){
            for(int i=0; i<mc_vector.size(); i++){
                int16_t rand_radius = rand() % 20 + 5;
                circle(final_contours, mc_vector[i], rand_radius, Scalar(0, 250, 0), -1, 8, 0);
            }
        }

        imshow("WINDOW img", img_resized);
        imshow("gaussian_blur", gaussian_blur);
        imshow("HSV 2", img_hsv2);
        imshow("WINDOW HSV", img_hsv);
        imshow("result", res);
        imshow("range HSV", HSV);
        imshow("final contours", final_contours);
        // imshow("canny_filter", canny_filter);
  
        // 180 300
        if(waitKey(1) == 32)
            break;

        // if(waitKey(1) == 47)
        //     flag = true;

        // if(waitKey(1) == 46)
        //     flag = false;

        cout << flag << endl;
    }
    // waitKey(0);
    return 0;
}