#include "impls.h"


std::vector<std::vector<cv::Point>> find_contours(const cv::Mat& input) {
    /**
     * 要求：
     * 使用cv::findContours函数，从输入图像（3个通道）中找出所有的最内层轮廓。
     * 将它们保存起来作为函数返回值就行。contours的中文意思就是轮廓。
     * 
     * 提示：
     * 1. 使用cv::imshow来查看输入图像。
     * 2. 使用cv::drawContours来在一张图上绘制轮廓。
     * 3. 直接使用原图一般而言不利于轮廓的寻找，可以做一些简单的处理。
     * 4. findContours函数可以返回轮廓的层次结构，理解层次结构的保存方式并使用它（重点）。
     * 
     * 通过条件：
     * 运行测试点，你找到的轮廓与答案的轮廓一样就行。
     */
    
    std::vector<std::vector<cv::Point>> res;
    //IMPLEMENT YOUR CODE HERE
    cv::Mat gray;
    cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);//转换为灰度

    cv::Mat binary;
    cv::threshold(gray, binary, 127, 255, cv::THRESH_BINARY);//二值化

    cv::imshow("Input Image", input);
    cv::imshow("Binary Image", binary);
    cv::waitKey(0);//展示图片等待下一步

    std::vector<std::vector<cv::Point>> contours;//轮廓数组
    std::vector<cv::Vec4i> hierarchy;//轮廓层次结构

    cv::findContours(binary, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
    //检测轮廓
    for (int i = 0; i < hierarchy.size(); i++) {
        if (hierarchy[i][2] == -1/*没有子轮廓*/ && hierarchy[i][3] != -1/*有父轮廓*/) {
            res.push_back(contours[i]);//符合条件就添加到res里
        }
    }

    cv::Mat contour_image = input.clone();
    cv::drawContours(contour_image, res, -1, cv::Scalar(0, 255, 0), 2);
                        /* -1表示绘制所有轮廓*/     /* 绿色标出 */    /* 线宽为2*/
    cv::imshow("Contours", contour_image);
    cv::waitKey(0);

    return res;
}