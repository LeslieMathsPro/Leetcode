#include <vector>
#include <iostream>

using namespace std;

void test_dim1_bag_problem(){
    vector<int> value = {15, 20, 30};
    vector<int> weight = {1, 3, 4};
    int bagWeight = 4;

    //初始化
    vector<int> dp(bagWeight+1, 0);
    for (int i = 0 ; i < weight.size(); ++i){
        for (int j = bagWeight; j>= weight[i]; --j){
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bagWeight] << endl;
}

int main(){
    test_dim1_bag_problem();
}