class Solution {
public:
    int findMaxCI(vector<int>& nums) {
        int count = 1;
        int maxCount = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i+1]) {
                count++;
            }
            else {
                count = 1;
            }
            if (count > maxCount) {
                maxCount = count;
            }
        }
        return maxCount;
    }
};