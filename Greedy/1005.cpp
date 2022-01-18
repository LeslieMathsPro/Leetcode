// class Solution {
// public:
//     int largestSumAfterKNegations(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         int sum = 0;
//         int countN = 0;
//         int countZ = 0;
//         for (int i = 0; i < nums.size(); i++){
//             if (nums[i] < 0) countN++;
//             if (num[i] == 0) countZ = 1;
//             if (num[i] > 0) break;
//         }

//         if (countN >= k) {
//             for (int i = 0; i < nums.size(); i++){
//                 if (i < k) sum+= -nums[i];
//                 else sum += nums[i];
//             }
//         } else {
//             if (countZ == 1) {
//                 for (int i = 0; i < nums.size(); i++){
//                     if (i < countN) sum += -nums[i];
//                     else sum += nums[i];
//                 }
//             } else {
//                 if((k - countN)%2 == 0){
//                     for(int i = 0; i < nums.size(); i++){
//                         if (i < countN) sum += -nums[i];
//                         else sum += nums[i];
//                     }
//                 }else{
//                     for(int i = 0; i < nums.size(); i++){
//                         if (i < countN + 1) sum += -nums[i];
//                         else sum += nums[i];
//                 }
//             }
//         }
//         return sum;
//     }
// };

class Solution {

static bool cmp(int a, int b){
    return abs(a) > abs(b);
}

public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size(); i++){
            if (A[i] < 0 && K > 0){
                A[i] *= -1;
                K--;
            }
        }
        if (K % 2 == 1) A[A.size()-1] *= -1;
        int result = 0;
        for (int a : A) result += a;
        return result;
    }
};