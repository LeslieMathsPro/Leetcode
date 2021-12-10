class Solution {
public:
    //取各位置上单数之和
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += (n%10) * (n%10);
            n/=10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> set;
        while (1) {
            int sum = getSum(n);
            if (sum == 1){
                return true;
            }
            //如果某个sum已经出现过，则表明陷入了无限循环
            if (set.find(sum) != set.end()){
                return false;
            }
            else {
                set.insert(sum);
            }
            n = sum;
        }
    }
};