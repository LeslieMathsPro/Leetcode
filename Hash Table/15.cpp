class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        // 排序之后如果第一个元素已经大于0，则无论如何都无法凑成三元组，直接返回结果就可以。
        {
            if (nums[i] > 0){
                return result;
            }

            //错误的去重方法，会漏掉-1，-1，2这种情况
            // if (nums[i] == nums[i+1]){
            //     continue;
            // }
            
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            int left = i + 1, right = nums.size() - 1;
            while(left < right){
                // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
                /*
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */
                if (nums[i] + nums[left] + nums[right] > 0 ){
                    right--;
                } else if (nums[i] + nums[left] + nums[right] < 0){
                    left++;
                } else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});\
                    //去重逻辑应该放在找到三元组之后
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;

                    //找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};