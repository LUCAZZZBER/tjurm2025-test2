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
    float contour_area = cv::contourArea(contour);// 轮廓面积
    
    if (contour_area == 0) {//防止分母是零
        return 0.f;
    }

    cv::RotatedRect min_rect = cv::minAreaRect(contour);// 获取最小外接矩形

    float rect_area = min_rect.size.width * min_rect.size.height;//求面积

    float area_ratio = contour_area / rect_area;//求比

    return area_ratio;
    
    }