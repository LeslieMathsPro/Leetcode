class Solution {
public:
    int longestSubsequence(string s, int k) {
        int result = 0;
        int n = s.size();
        long sum = 0;
        //int index = 0;
        int times = 1;
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                result++;
                time *= 2;
            } else {
                if (sum + times <= k) {
                    sum += times;
                    result++;
                }
            }
        }

        return result;
    }
};