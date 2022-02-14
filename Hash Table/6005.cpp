class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size(), max0 = 0, max0_ = 0, max1 = 0, max1_ = 0, x, y;
        if (n == 1) return 0;
        else if (n == 2) return num[0] == nums[1];
        unordered_map<int, int> cnt0, cnt1;
        for (int i = 0; i < n; ++i)
        {
            if (i%2){
                ++cnt1[nums[i]];
                if(cnt1[nums[i]] > max1){
                    x = nums[i];
                    max1 = cnt1[nums[i]];
                }
            }
        }

    }
};