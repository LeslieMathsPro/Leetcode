class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0; //滑动窗口数值之和
        int i = 0; //滑动窗口起始位置
        int sublength = 0; //滑动窗口的长度
        for (int j = 0; j < nums.size(); ++j){
            sum += nums[j];
            //注意这里使用while，每次更新i起始位置，并不断比较子序列是否符合要求
            while (sum >= target){
                sublength = j - i + 1; //取子序列的长度
                result = result < sublength? result : sublength;
                sum -= nums[i++];
            }
        }
        return result == INT32_MAX? 0 : result;
    }
};