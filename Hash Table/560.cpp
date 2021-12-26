class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, n = nums.size();
        vector<int> prefix(n, 0); //以i元素结尾的[0,i]区间前缀和
        prefix[0] = nums[0];
        for (int i = 0; i < n; i++){
            prefix[i+1] = nums[i+1] + prefix[i]; //求前缀和的通向公式 
        }
        unordered_map<int, int> prefixMap; //key为前缀和，value为次数
        prefixMap[0] = 1; //令prefix[-1] = 0; prefix[0] = prefix[-1] + nums[0];
        for (int i - 0; i < n; i++){//[j:i]区间的前缀和为k，prefix[i] - prefix[j - 1] = k;
            if (prefixMap.find(prefix[i] - k) != prefixMap.end()){//0<=j<=i
                count+=prefixMap[prefix[i] - k];
            }
            prefixMap[prefix[i]]++;//不能提前计算前缀和，只能一边计算一边统计前缀和与数量，因为要保证0<=j<=i。
        }
        return count;
    }
};