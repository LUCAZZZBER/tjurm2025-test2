#include "impls.h"
#include <opencv2/opencv.hpp>
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
    //std::pair<cv::Rect, cv::RotatedRect> res;
    // IMPLEMENT YOUR CODE HERE
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    
    // 转换为灰度图
    cv::Mat gray;
    cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
    
    // 二值化
    cv::Mat binary;
    cv::threshold(gray, binary, 100, 255, cv::THRESH_BINARY_INV);
    
    // 查找轮廓
    cv::findContours(binary, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    
    cv::Rect bestRect;
    cv::RotatedRect bestRotatedRect;
    double maxArea = 0;
    
    for (size_t i = 0; i < contours.size(); i++) {
        // 近似轮廓
        std::vector<cv::Point> approx;
        cv::approxPolyDP(contours[i], approx, cv::arcLength(contours[i], true) * 0.02, true);
        
        // 检查轮廓是否为矩形（4个点）
        if (approx.size() == 4) {
            // 计算外接矩形
            cv::Rect rect = cv::boundingRect(contours[i]);
            cv::RotatedRect rotatedRect = cv::minAreaRect(contours[i]);
            
            // 计算轮廓面积
            double area = cv::contourArea(contours[i]);
            
            // 更新最大面积的矩形和最小面积外接矩形
            if (area > maxArea) {
                maxArea = area;
                bestRect = rect;
                bestRotatedRect = rotatedRect;
            }
        }
    }
    
    return std::make_pair(bestRect, bestRotatedRect);
}