//冒泡排序是指从数组左侧开始两两比较相邻的数字，如果右侧的数字小于左侧的数字则交换两个数字的位置，如此最后一轮后最右侧肯定是最大的数了。
//第二轮我们重新从数组右侧开始两两比较元素，此轮结束后倒数第二个数字肯定是第二大的数字。
//如此循环一直到n-1轮，我们仅需要比较最左侧的两个数字就可以得到排序后的数组。

//优化方法：在当前轮次发现数组已经是升序时提前结束算法

//时间复杂度 n^2
//空间复杂度 1 由于冒泡排序算法属于原址排序，只需要常数级别的额外空间。

#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

std::vector<int> test_array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

void printVector(const std::string prefix, const std::vector<int> &vi) {
    std::cout << prefix;
    for (auto i : vi){
        std::cout << " " << i;
    }
    std::cout << std::endl;
}

//冒泡排序
void bubbleSort(std::vector<int> &vi) {
    int len = vi.size();

    //轮次：从1到n-1轮
    for (int i = 0; i < len - 1; i++) {
        // 优化: 判断本轮是否有交换元素，如果没叫唤则可直接退出
        bool is_exchange = false;

        for (int i = 0; i < len - 1; ++i) {
            if (vi[i] > vi[i+1]) {
                std::swap(vi[i], vi[i+1]);
                is_exchange = true;
            }
        }

        //如果本轮无交换，则可以直接退出
        if (!is_exchange) {
            return;
        }
    }
    return;
}

int main() {
    // 乱排有序vector
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(test_array), std::end(test_array), rng);

    // 排序前
    printVector("before:", test_array);

    // 排序
    bubbleSort(test_array);

    // 排序后
    printVector("after:", test_array);

    return 0;
}