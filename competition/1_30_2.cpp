class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0); //初始化一个n+1的0向量
        for (int i = 0; i < n; ++i) {
            dp[0] += nums[i];
        }
        //dp[0] = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 1; i < n+1; ++i){
            if (nums[i - 1] == 0){
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = dp[i - 1] - 1;
            }
        }
        int maxDp = 0;
        for (int i = 0; i < n+1; ++i) {
            if (maxDp < dp[i]){
                maxDp = dp[i];
            }
        }
        //int M = max_element(dp.begin(), dp.end());
        vector<int> result;
        for (int j = 0; j < n+1; ++j){
            if (nums[j] == maxDp){
                result.push_back(j);
            }
        }
        return result;
    }
};