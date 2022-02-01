class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int i : stones){
            sum += i;
        }
        int target = sum / 2;
        vector<int> dp(15000, 0);
        for(int i = 0; i < stones.size(); ++i){
            for (int j = target; j >= stones[i]; --j){
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        int result = 0;
        result = (sum - dp[target]) - dp[target];
        return result;
    }
};