// class Solution {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      * 
//      * @param heights int整型vector 
//      * @return int整型vector
//      */
//     int getNumber(vector<int>& heights, int i){
//         int preNumber = 0;
//         int preMax = 0;
//         int midNumber = 1;
//         int backNumber= 0;
//         int backMax = 0;
//         int n = heights.size();
//         int TotalNumber;
//         //前
//         if (i - 1 >= 0){
//             preMax = heights[i - 1];
//             preNumber = 1;
//         }
//         while (i - 2 >= 0){
//             if (heights[i - 2] > preMax){
//                 preMax = heights[i - 2];
//                 preNumber++;
//             }
//             i--;
//         }
//         //后
//         if (i + 1 <= n - 1){
//             backMax = heights[i+1];
//             backNumber = 1;
//         }

//         while (i + 2 <= n - 1){
//             if (heights[i + 2] > backMax){
//                 backMax = heights[i + 2];
//                 backNumber++;
//             }
//             i++;
//         }
//         TotalNumber = preNumber + midNumber + backNumber;
//         return TotalNumber;
//     }

//     vector<int> findBuilding(vector<int>& heights) {
//         // write code here
//         int n = heights.size();
//         vector<int> result(n);
//         for (int i = 0; i < n; i++){
//             result[i] = getNumber(heights, i);
//         }
//         return result;
//     }
// };