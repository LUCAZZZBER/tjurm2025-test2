#include "impls.h"


cv::Mat my_resize(const cv::Mat& input, float scale) {
    /**
     * 要求：
     *      实现resize算法，只能使用基础的语法，比如说for循环，Mat的基本操作。不能
     * 用cv::resize。resize算法的内容自行查找学习，不是很难。
     * 
     * 提示：
     * 无。
     * 
     * 通过条件：
     * 运行测试点，你的结果跟答案长的差不多就行。
     */
    //int new_rows = input.rows * scale, new_cols = input.cols * scale;
    // IMPLEMENT YOUR CODE HERE
    int new_rows = static_cast<int>(input.rows * scale);
    int new_cols = static_cast<int>(input.cols * scale);

    cv::Mat output = cv::Mat::zeros(new_rows, new_cols, input.type());

    // 遍历目标图像的每个像素
    for (int i = 0; i < new_rows; ++i) {
        for (int j = 0; j < new_cols; ++j) {
            // 计算对应的源图像坐标
            float x = static_cast<float>(j) / scale;
            float y = static_cast<float>(i) / scale;

            // 找到最接近的整数坐标
            int x1 = static_cast<int>(x);
            int y1 = static_cast<int>(y);

            // 确保坐标在源图像范围内
            if (x1 >= 0 && x1 < input.cols && y1 >= 0 && y1 < input.rows) {
                // 使用最近邻插值
                output.at<cv::Vec3b>(i, j) = input.at<cv::Vec3b>(y1, x1);
            }
        }
    }

    return output;
}