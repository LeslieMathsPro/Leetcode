class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        if (nums.size() <= 2) return nums;
        vector<int> odd, even;
        for (int i = 0; i < nums.size(); ++i){
            if (i % 2 == 0) {
                even.push_back(nums[i]);
            } else {
                odd.push_back(nums[i]);
            }
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        reverse(odd.begin(), odd.end());

        vector<int> result;

        for (int i = 0; i < nums.size(); ++i){
            if (i%2 == 0) {
                result.push_back(even[i/2]);
            } else {
                result.push_back(odd[(i-1)/2]);
            }
        }

        return result;
    }
};