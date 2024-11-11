#include "impls.h"
#include <vector>

std::pair<cv::Rect, cv::RotatedRect> get_rect_by_contours(const cv::Mat& input) {
    /**
     * 要求：
     * 使用findCountours函数找出输入图像（彩色图像）中的矩形轮廓，并且返回它的外接矩形，以及
     * 最小面积外接矩形。所需要的函数自行查找。
     * 
     * 通过条件：
     * 运行测试点，你找到的矩形跟答案一样就行。
    */
    // IMPLEMENT YOUR CODE HERE
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    
    cv::Mat gray;
    cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);

    cv::Mat binary;
    cv::threshold(gray, binary, 100, 255, cv::THRESH_BINARY_INV);

    cv::findContours(binary, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    
    cv::Rect bestRect;
    cv::RotatedRect bestRotatedRect;
    double maxArea = 0;
    
    for (size_t i = 0; i < contours.size(); i++) {
        std::vector<cv::Point> approx;
        cv::approxPolyDP(contours[i], approx, cv::arcLength(contours[i], true) * 0.02, true);
        
        if (approx.size() == 4) {
            cv::Rect rect = cv::boundingRect(contours[i]);
            cv::RotatedRect rotatedRect = cv::minAreaRect(contours[i]);
            
            double area = cv::contourArea(contours[i]);
            
            if (area > maxArea) {
                maxArea = area;
                bestRect = rect;
                bestRotatedRect = rotatedRect;
            }
        }
    }
    
    return std::make_pair(bestRect, bestRotatedRect);
}