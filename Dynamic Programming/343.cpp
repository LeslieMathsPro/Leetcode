// class Solution {
// public:
//     int integerBreak(int n) {
//         vector<int> dp(n+1);
//         dp[0] = 0;
//         dp[1] = 1;
//         dp[2] = 1;
//         if (n<=2) return dp[n];
//         for (int i = 3; i <= n; i++)
//         {
//             for (int j = 2; j < i; j++)
//             {
//                 dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
//             }
//         }
//         return dp[n];
//     }
// };

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i < dp.size(); i++){
            for (int j = 1; j < i; j++){
                dp[i] = max(dp[i], max(dp[i - j]*j, (i - j)*j));
            }
        }
        return dp[n];
    }
};