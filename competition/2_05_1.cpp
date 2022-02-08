class Solution {
public:
    int minimumSum(int num) {
        int a, b, c, d;
        a = num%10;
        num /= 10;
        b = num%10;
        num /= 10;
        c = num%10;
        num /= 10;
        d = num%10;
        vector<int> result;
        result.push_back(a);
        result.push_back(b);
        result.push_back(c);
        result.push_back(d);
        sort(result.begin(),result.end());
        int R;
        R = (result[0] + result[1])*10 + result[2] + result[3];
        return R;
    }
};