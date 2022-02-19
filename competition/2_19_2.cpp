class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long pre, ind, aft;
        vector<long long> result;
        if (num % 3 != 0) return result;
        ind = num / 3;
        pre = ind - 1;
        aft = ind + 1;
        result.push_back(pre);
        result.push_back(ind);
        result.push_back(aft);

        return result;
    }
};