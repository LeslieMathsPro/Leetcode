// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         if (n < 2) return 0;
//         if (n == 2) return min(cost[0], cost[1]);
//         //vector<int> dp(n); //注意这里的初始化一定要加dp(n)
//         //如果用减少空间内存的方法去写
//         int a = cost[0];
//         int b = cost[1];
//         for (int i = 2; i < n; i++)
//         {
//             //dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
//             int c = min(a, b) + cost[i]
//             a = b;
//             b = c;
//         }
//         return min(a, b);
//     }
// };

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < cost.size(); i++){
            dp[i] = min(dp[i-2], dp[i-1]) + cost[i];
        }
        return min(dp[cost.size() - 2], dp[cost.size() - 1]);
    }
};

// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int dp0 = cost[0];
//         int dp1 = cost[1];
//         for (int i = 0; i < cost.size(); i++){
//             int dpi = min(dp0, dp1) + cost[i];
//             dp0 = dp1;
//             dp1 = dpi;
//         }
//         return min(dp[0], dp[1]);
//     }
// };