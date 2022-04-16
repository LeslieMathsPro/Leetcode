class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int sum = INT_MIN;
        int maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < nums.size(); j++){
                if(i == j) continue;
                sum = nums[i] + nums[j];
                if(sum < k && sum > maxSum){
                    maxSum = sum;
                }
            }
        }
        if (maxSum == INT_MIN) return -1;
        else return maxSum;
    }
};