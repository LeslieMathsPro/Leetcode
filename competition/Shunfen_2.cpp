class Solution {
public:
    int minRemainingSpace(vector<int>& N, int V) {
        // N = [8, 1, 12, 7, 9, 7], V = 11
        //[8, 2, 12, 7, 9, 7]
        // 暴力 + 回溯
        sort(N.begin(), N.end());
        reverse(N.begin(), N.end());
        // N = [12, 9, 8, 7, 7, 1], V = 11
        //[12, 9, 8, 7, 7, 2]
        int res = V; // res = 11;
        for (int i = 0; i < N.size(); i++) {
            if (N[i] <= res) {
                res -= N[i];
            }

        }

        return res;
    }
};



class Solution {
public:
    int minRemainingSpace(vector<int>& N, int V) {
        int n = N.size();
        vector<int> dp(V, 0);
        for (int i = 0; i < n; i++) {
            for (int j = V; j >= N[i]; j--) {
                if (f[j] < dp[j - N[i]] + N[i]) {
                    f[j] = dp[j-N[i]] + N[i];
                }
            }
        }
        return V - f[V];
    }
};