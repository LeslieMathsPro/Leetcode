//第一轮: 在未排序数组中找到最小值，和数组最左侧元素交换
//第二轮: 从剩余未排序元素中找到最小值，然后和数组第二个元素交换
//重复第二轮直到第n-1轮结束

//时间复杂度 n^2
//空间复杂度 1

#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

std::vector<int> test_array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

// 打印vector内容
void printVector(const std::string prefix, const std::vector<int> &vi) {
    std::cout << prefix;
    for (auto i : vi) {
        std::cout << " " << i;
    }
    std::cout << std::endl;
}

void selectSort(std::vector<int> &vi) {
    //需要进行 n-1 轮
    for (int i = 0; i < vi.size() - 1; ++i) {
        //找到此轮的最小值下标
        int mini_index = i;
        for (int j = i + 1; j < vi.size(); ++j) {
            if (vi[j] < vi[mini_index]) {
                mini_index = j;
            }
        }
        std::swap(vi[i], vi[mini_index]);
    }
}



int main() {
    // 乱排有序vector
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(test_array), std::end(test_array), rng);

    // 排序前
    printVector("before:", test_array);

    // 排序
    selectSort(test_array);

    // 排序后
    printVector("after:", test_array);

    return 0;
}