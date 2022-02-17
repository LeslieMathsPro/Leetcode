class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i)
        {
            map.insert(pair<int, int> (nums[i], i));
        }
        for (int j = 0; j < nums.size(); ++j)
        {
            auto iter = map.find(target - nums[j]);

            if (iter != map.end())
            {
                if(iter->second != j) {
                    result.push_back(j);
                    result.push_back(iter->second);
                    break;
                } else {
                    continue;
                }
            }
        }
        return result;
    }
};