class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int SlowIndex = 0;
        for (int FastIndex = 0; FastIndex < nums.size(); FastIndex++){
            if (val != nums[FastIndex]) {
                nums[SlowIndex++] = nums[FastIndex];
            }
        }
        return SlowIndex;
    }
};