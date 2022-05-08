class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        for (; i < nums.size(); i++)
        {
            if (i != nums[i]) break; 
        }
        return i;
    }
};