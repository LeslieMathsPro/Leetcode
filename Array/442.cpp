class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int x: nums)
        {
            int t = abs(x) - 1;
            if (nums[t] < 0) ans.push_back(t + 1);
            else nums[t] = -nums[t];
        }
        return ans;
    }
};