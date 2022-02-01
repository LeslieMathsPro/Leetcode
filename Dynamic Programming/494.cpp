class Solution {
    //若S中加法的总和为X，那么减法的总和为SUM-X
    //因而我们要求的便是X-(SUM-X) = S, 即X=(S+SUM)/2.
    //此时问题就转化为装满容量为X的背包，共有几种方法。
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //dp[j]表示：填满j(包含j)这么大容积的包，有dp[j]种方法。
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) sum += nums[i];
        if (abs(target) > sum) return 0;
        if ((target + sum) % 2) return 0;
        int bagsize = (target + sum) / 2;
        vector<int> dp(nums.size() + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i){
            for (int j = bagsize; j >= nums[i]; --j)
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagsize];
    }
};