// dp[i][j]含义：从下标为0-i的物品里任意取，放进容量为j的背包，价值总和的最大为多少

// 那么一共有两种方向来推出dp[i][j]
// 1. 不放物品i， 有dp[i-1][j]推出，即背包容量为j，其中不放物品i的最大价值。此时dp[i][j]就是dp[i-1][j]
// 其实就是当物品i的重量大于背包j的重量时， 物品i无法放入背包中，所以背包内的价值依然和前面相同
// 2. 放物品i，由dp[i-1][j-weight[i]]推出, 即dp[i - 1][j - weight[i]] + value[i]
// 因此递归公式为: dp[i][j] = max(dp[i-1][j], dp[i - 1][j - weight[i]] + value[i]);

// dp初始化
// 首先从dp的定义出发，如果背包的容量为0 即dp[i][0]，无论选取哪些物品，背包的价值总和一定为0
// 由状态转移方程可以看出是由i-1推导出来的，那么i为0时候的初始值就一定要初始化。
#include "head.h"
void test_2_dim_bag_problem1(){
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;

    //二维数组
    vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));

    //初始化
    for (int j = weight[0]; j <= bagweight; j++){
        dp[0][j] = value[0];
    }

    //weight数组的大小，就是物品的个数
    for(int i = 1; i < weight.size(); i++){ //遍历物品
        for (int j = 0; j <= bagweight; j++){ //遍历背包容量
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }
    cout << dp[weight.size() - 1][bagweight] << endl;
}

int main() {
    test_2_dim_bag_problem1();
}