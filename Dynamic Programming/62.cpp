// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, 0)); // 如何定义一个二维数组   
//         for (int i = 0; i < m; i++) dp[i][0] = 1;
//         for (int j = 0; j < n; j++) dp[0][j] = 1;
//         for (int i = 1; i < m; i++)
//         {
//             for (int j = 1; j < n; j++)
//             {
//                 dp[i][j] = dp[i-1][j] + dp[i][j-1];
//             }
//         }
//         return dp[m][n];
//     }
// };

// //化为单维的方法
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<int> dp(m);
//         for (int i = 0; i < m; i++)
//         {
//             dp[i] = 1;
//         }
//         for (int j = 1; j < n; j++)
//         {
//             for (int i = 1; i < m; i++)
//             {
//                 dp[i] += dp[i-1];
//             }
//         }
//         return dp[m - 1];
//     }
// };
// //数论的方法


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m-1][n-1];
    }
};