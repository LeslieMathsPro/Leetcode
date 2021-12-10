// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int n = nums.size();
//         int l = 0, r = nums.size() - 1;
//         vector<int> squarenums[n];
//         while (l < r){
//             if (nums[l]**2 <= nums[r]**2){
//                 squarenums[n-1] = nums[r]**2;
//                 n -=1;
//             }
//             else {
//                 squarenums[n-1] = nums[l]**2;
//                 n -=1;
//             }
//         }
//     }
// };

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int k = nums.size() - 1;
        vector<int> result(nums.size, 0);
        for (int i = 0, j = nums.size() - 1; i <= j; ){
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                result[k] = nums[j] * nums[j];
                k--;
                j--;
            }else{
                result[k] = nums[i] * nums[i];
                k--;
                i++;
            }
        }
        return result;
    }
};