class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end()); //先排序
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < original) {
                continue;
            }
            else if (nums[i] == original) {
                original *= 2;
            }
            else {
                break;
            }
        }
        return original;
    }
};