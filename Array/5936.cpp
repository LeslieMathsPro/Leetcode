class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> nums1 = nums;
        sort(nums1.begin(), nums1.end());
        vector<int> nums2(&nums1[0], &nums1[k]);
        vector<int> index(k, 0);
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] == nums2[k])  index[k] = j;
            }
        }
        for (int i = 0; i < k; i++)
        {
            for (int j = i+1; j<k; j++)
            {
                if (index[i] > index[j])
                    swap(nums2[i], nums2[j]);
            }
        }
        return nums2;
    }
};