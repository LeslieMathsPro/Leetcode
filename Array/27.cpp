//暴力解
// int removeElement(vector<int>& nums, int val) {
//     int n = nums.size();

//     for (int i = 0; i < n; i++){
//         if (nums[i] == val){
//             for (int j = i+1; j < n; j++){
//                 nums[j-1] = nums[j];
//             }
//             j--;
//             n--;
//         }
//     }
//     return n;
// }


//双指针
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex<nums.size(); fastIndex++){
            if (val != nums[fastIndex]){
                nums[slowIndex++] = num[fastIndex];
            }
        }
        return slowIndex;
    }
};