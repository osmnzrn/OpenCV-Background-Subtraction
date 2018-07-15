#include<opencv2/opencv.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/imgcodecs/imgcodecs.hpp>
#include<opencv2/videoio.hpp>
#include<iostream>
#include<vector>

int main(int argc, char *argv[])
{
    cv::Mat frame;
    cv::Mat fg;
    
    cv::VideoCapture cap("walking.mp4"); //video source
    cv::Ptr<cv::BackgroundSubtractor> 

    bg = cv::createBackgroundSubtractorMOG2(500, 16, false);

    std::vector<std::vector<cv::Point> > contours;

    cv::namedWindow("Frame");

    for(;;)
    {
        cap >> frame;
        bg->apply(frame,fg);
       
        cv::erode(fg,fg,cv::Mat());
        cv::dilate(fg,fg,cv::Mat());
        
        cv::findContours(fg.clone(),contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);
        cv::drawContours(frame,contours,-1,cv::Scalar(0,255,0),2);

        cv::imshow("Frame",frame);
       
        if(cv::waitKey(30) >= 0) break;
    }
    return 0;
}