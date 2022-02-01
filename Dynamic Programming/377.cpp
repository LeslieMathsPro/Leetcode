class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 0; i <= target; ++i)
        {
            for (int j = 0; j < nums.size(); ++j)
            {
                if (i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]]) //测试用例中有两个数相加超过int的数据，因此需要dp[i] + dp[i - num[j]] < INT_MAX
                {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};