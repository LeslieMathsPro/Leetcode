class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int majority = 0, count = 0;
        for (int num:nums)
        {
            ++counts[num];
            if(counts[num] > count)
            {
                majority = num;
                count = counts[num];
            }
        }
        return majority;
    }
};