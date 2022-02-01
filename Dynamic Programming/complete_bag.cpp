#include <iostream>
#include <vector>

using namespace std;

int test_CompletePack(){
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    vector<int> dp(weight.size()+1, 0);
    for (int i = 0; i < weight.size(); ++i)
    {
        for (int j = weight[i]; j <= bagWeight; ++j)
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[bagWeight];
}

int main(){
    int result = 0;
    result = test_CompletePack();
    cout << result << endl;    
}