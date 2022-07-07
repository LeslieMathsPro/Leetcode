class Solution {
//只有确定了以下四点，才能把01背包问题套到本题上来
//1. 背包的体积要为sum/2
//2. 背包要放入的商品(集合里的元素)，重量为元素的数值，价格也为元素的数值
//3. 背包如果正好装满，说明找到了总和为sum/2的集合
//4. 背包中每个元素都是不可重复放入的

public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        
        vector<int> dp(10001, 0);
        for (int i = 0; i < nums.size(); ++i){
            sum += nums[i];
        }
        if (sum % 2) return false;
        int target = sum / 2;

        //开始01背包
        for (int i = 0; i < nums.size(); ++i){
            for (int j = target; j >= nums[i]; j--){
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        //集合中的元素正好可以凑成总和target
        if(dp[target] = target) return true;
        return false;
    }

    
};