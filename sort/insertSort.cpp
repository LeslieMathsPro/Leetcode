//时间复杂度为 n^2
//空间复杂度为n

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

//插入排序
void insertSort(std::vector<int> &vi) {
    // 第一轮不需要操作，第二轮比较一次，第n轮比较n-1次
    for (int i = 1; i < vi.size(); ++i) {
        // 存储待插入的值和下标
        int insert_value = vi[i];
        int j = i - 1;

        while (j >= 0 && vi[j] > insert_value) {
            vi[j + 1] = vi[j]; //如果左侧的已排序元素比目标值大，那么右移
            j--;
        }
        vi[j + 1] = insert_value;
    }
}


int main() {
    // 乱排有序vector
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(test_array), std::end(test_array), rng);

    // 排序前
    printVector("before:", test_array);

    // 排序
    insertSort(test_array);

    // 排序后
    printVector("after:", test_array);

    return 0;
}