// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         for (int i = 0; i < cost.size(); i++){
//             int rest = gas[i] - cost[i]; //记录剩余油量
//             int index = (i + 1) % cost.size();
//             while (rest > 0 && index != i)  { //模拟以i为起点行驶一圈
//                 rest += gas[index] - cost[index];
//                 index = (index + 1) % cost.size(); 
//             }
//             //如果以i为起点跑一圈，剩余油量大于等于0，则返回该起始位置
//             if (rest >= 0 && index == i) return i;
//         }
//         return -1;
//     }
// };

// 贪心算法一整体最优
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int curSum = 0;
//         int min = INT_MAX; //从起点出发，油箱里油量最小值
//         for (int i = 0; i < gas.size(); i++) {
//             int rest = gas[i] - cost[i];
//             curSum += rest;
//             if (curSum < min) min = curSum;
//         }
//         if (curSum < 0) return -1;
//         if (min >= 0) return 0;

//         for (int i = gas.size() - 1; i >= 0; i--) {
//             int rest = gas[i] - cost[i];
//             min += rest;
//             if (min >= 0) return i;
//         }
//         return -1;
//     }
// };

//贪心算法 局部最优
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < cost.size(); i++){
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) {
                start = i + 1;
                curSum = 0;
            }
        }
        if (totalSum < 0) return -1;
        return start;
    }
};