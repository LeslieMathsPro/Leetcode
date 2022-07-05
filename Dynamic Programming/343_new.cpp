//dp[i] 拆分数字i，可以得到的最大乘积为dp[i]
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1);
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j < i - 1; j++) {
            dp[i] = max(dp[i], max((i-j)*j, dp[i-j] * j));
        }
    }
    cout << dp[n] << endl;
    return 0;
}