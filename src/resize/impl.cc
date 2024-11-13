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
    int new_rows = input.rows * scale, new_cols = input.cols * scale;
    // IMPLEMENT YOUR CODE HERE
   

    cv::Mat output = cv::Mat::zeros(new_rows, new_cols, input.type());
                        //创建一个矩阵初值为零            //数据类型和input相同
    for (int i = 0; i < new_rows; ++i) {
        for (int j = 0; j < new_cols; ++j) {
            float x = static_cast<float>(j) / scale;
            float y = static_cast<float>(i) / scale;

            int x1 = static_cast<int>(x);
            int y1 = static_cast<int>(y);

            if (x1 >= 0 && x1 < input.cols && y1 >= 0 && y1 < input.rows) {
                output.at<cv::Vec3b>(i, j) = input.at<cv::Vec3b>(y1, x1);
            }            //三个通道
        }
    }

    return output;
}