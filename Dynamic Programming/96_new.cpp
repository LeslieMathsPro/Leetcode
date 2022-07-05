//dp[i] 1到i为节点组成的二叉搜索树的个数为dp[i]
#include <iostream>
#include <vector>


using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1);

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    cout << dp[n] << endl;
    return 0;
}