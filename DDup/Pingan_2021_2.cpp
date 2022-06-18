//查找字符串最长公共子串
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string a = "1234567";
    string b = "12893457";
    //cin >> a >> b;
    int m = a.size();
    int n = b.size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = a[0] == b[0] ? 1:0;

    //这里有问题
    for (int i = 1; i < m; i++) {
        dp[0][i] = a[i] == b[0] ? 1:0;
    }
    for (int j = 0; j < n; j++) {
        dp[j][0] = a[0] == b[j] ? 1:0;
    }

    int stored_i, stored_j;
    int maxValue = 0;

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (a[i] != b[j]) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > maxValue) {
                    maxValue = dp[i][j];
                    stored_i = i;
                    stored_j = j;
                }
            }
        }
    }

    string result = a.substr(stored_i, maxValue);

    cout << result << endl;
    return 0;
}