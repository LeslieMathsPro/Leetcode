//10x9 的网格
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int m = 10;
    int n = 9;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    //初始化
    for (int i = 0; i < n; ++i){
        dp[0][i] = 1; 
    }
    for (int j = 0; j < m; ++j){
        dp[j][0] = 1;
    }
    //动态规划
    for(int i = 1; i < n; ++i){
        for(int j = 1; j < m; ++j){
            dp[j][i] = dp[j-1][i] + dp[j][i-1];
        }
    }
    cout << dp[m-1][n-1] << endl;
}