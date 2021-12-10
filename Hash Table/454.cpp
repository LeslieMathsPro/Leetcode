class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap; // key:a+b的数值，value:a+b数值出现的次数
        //遍历nums1 和nums2数组，统计两个数组的元素之和和出现的次数，放到map中。
        for (int a : nums1){
            for (int b :nums2){
                umap[a+b]++;
            }
        }
        int count = 0; //统计a+b+c+d=0出现的次数
        //遍历nums3 和nums4数组，找到如果(0-c-d)在umap中出现过的话，就把map中的key对应的value也就是出现过的次数统计出来。
        for (int c:nums3){
            for (int d:nums4){
                if (umap.find(0-c-d)!=umap.end()){
                    count += umap[0-c-d];
                }
            }
        }
        return count;
    }
};