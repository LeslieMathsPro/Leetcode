class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int a = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            a |= nums[i];
        }
        return a;
    }
};