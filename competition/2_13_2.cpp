class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        if (nums.size() <= 2) {return 0;}
        vector<int> odd;
        vector<int> even;
        for (int i = 0; i < nums.size(); ++i){
            if(i%2) {odd.push_back(nums[i]);}
            else {even.push_back(nums[i]);}
        }
        //统计odd类与even类的众数
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        int max_oc_odd = 0;
        int max_oc_even = 0;
        int count = 1;
        int result = 100000;
        for (int i = 0; i < odd.size() - 1; ++i){
            if (odd[i] == odd[i+1]) {
                count++;
            } else {
                count = 1;
            }
            max_oc_odd = count > max_oc_odd? count : max_oc_odd;
        }
        for (int i = 0; i < even.size() - 1; ++i){
            if (even[i] == even[i+1]) {
                count++;
            } else {
                count = 1;
            }
            max_oc_even = count > max_oc_even? count : max_oc_even;
        }
        result = nums.size() - max_oc_even - max_oc_odd;
        return result;
    }   
};