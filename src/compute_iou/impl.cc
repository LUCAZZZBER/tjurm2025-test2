#include "impls.h"
#include <algorithm>

float compute_iou(const cv::Rect& a, const cv::Rect& b) {
    /**
     * 要求：
     *      有一个重要的指标叫做“交并比”，简称“IOU”，可以用于衡量
     * 两个矩形的重合程度，本练习要求自行学习交并比的计算方式，计算输入
     * 的两个矩形的交并比。
     * 
     * 提示：
     * (1) 注意OpenCV中规定的xy坐标系方向跟平常的xy坐标系不一样。
     * (2) 注意矩形的x, y, width, height四个属性在坐标系内的含义。
     * (3) 注意分母不要除以0（不过我们不会测试这一点）
     *  
     * 通过条件：
     * 运行测试点，显示通过就行，不通过会告诉你哪一组矩形错了。
    */
    // IMPLEMENT YOUR CODE HERE
    int x1 = std::max(a.x, b.x);
    int y1 = std::max(a.y, b.y);// 找左上角
    int x2 = std::min(a.x + a.width, b.x + b.width);
    int y2 = std::min(a.y + a.height, b.y + b.height);// 找右下角

    int intersection_width = std::max(0, x2 - x1);// 出现负数说明没交上
    int intersection_height = std::max(0, y2 - y1);

    int intersection_area = intersection_width * intersection_height;//交集面积

    int area_a = a.width * a.height;//分别的面积
    int area_b = b.width * b.height;

    int union_area = area_a + area_b - intersection_area;// 并集面积

    float iou = static_cast<float>(intersection_area) / union_area;//比

    return iou;
}