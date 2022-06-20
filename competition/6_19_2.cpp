class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0) return 0;
        if (k == 0) return (num%10 == 0 ? 1:-1);
        // num = 20, k = 4
        int res = num%10; // res = 0
        int n = num/10;  // n = 2
        vector<int> vec(n+1, 0); //(0, 10, 20)
        vec[0] = res;
        for (int i = 1; i <= n; i++) {
            vec[i] = vec[i-1] + 10;
        }

        //10 8
        //res = 0, n = 1
        //(0, 10)

        int result = -1;
        if (res == 0) {
            for (int i = 1; i < n+1; i++) {
                if (vec[i]%k == 0) {
                    result = vec[i]/k;
                    return result;
                }
            }
            return -1;
        }

        for (int i = 0; i < n+1; i++) {
            if (vec[i]%k == 0) {
                result = vec[i]/k;
                return result;
            }
        }

        return result;
    }
};