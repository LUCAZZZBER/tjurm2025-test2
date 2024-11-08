#include "impls.h"


 float compute_area_ratio(const std::vector<cv::Point>& contour) {
        /**
         * 要求：
         *      计算输入的轮廓的面积与它的最小外接矩形面积的比例。自行查找
         * 获得轮廓面积的函数。这个量可以用来判断一个轮廓到底有多靠近一个矩形。
         * 
         * 提示：
         * 无。
         * 
         * 通过条件:
         * 运行测试点，通过即可。
         */
        // 计算轮廓的面积
    double contour_area = cv::contourArea(contour);
    
    // 如果轮廓面积为0，返回0，避免除以0的错误
    if (contour_area == 0) {
        return 0.f;
    }

    // 获取轮廓的最小外接矩形
    cv::RotatedRect min_rect = cv::minAreaRect(contour);


    // 计算最小外接矩形的面积
    float rect_area = min_rect.size.width * min_rect.size.height;


    // 计算比例
    float area_ratio = static_cast<float>(contour_area) / rect_area;

    return area_ratio;
    
    
    }