class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int max, min;
        for(int i = 0; i < n - 1; i++){
            max = min = nums[i];
            for(int j = i + 1; j < n; j++){
                max = fmax(max, nums[j]);
                min = fmin(min, nums[j]);
                ans += max - min;
            }
        }
        return ans;
    }
};