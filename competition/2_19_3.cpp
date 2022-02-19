class Solution {
public:

    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> result;
        if (finalSum % 2 != 0) return result;
        //01背包问题, 最多取一次， 要求取得种类最多， 使得达到finalSum
        //首先用回溯方法 trial
        long long halfFinalSum = finalSum / 2;
        //裂变法
        long long i = 1;
        while (halfFinalSum - i > 0){
            halfFinalSum -= i;
            result.push_back(i*2);
            i+=1;
        }
        if (halfFinalSum - i == 0){
            result.push_back(i*2);
        } else {
            long long idx = i - halfFinalSum;
            result[idx - 1] = i*2;
        }
        return result;
    }
};