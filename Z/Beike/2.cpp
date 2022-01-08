class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @param m long长整型 
     * @return long长整型vector
     */

    //写一个模拟
    vector<long> FarmerNN(int n, long long m) {
        // write code here
        int index = 0;
        vector<long> result(n); //初始化用于保存结果的向量
        //2*n-2 为一个周期, m模(2*n-2)的余数是我们需要最后单独考虑的情况
        if (m > 2*n - 2) {
            long times = m/(2*n-2);
            //vector<long> result(n,times*2);
            for (int i = 0; i < n; i++){
                result[i] = times * 2;
            }

            result[0] = result[0]/2;
            result[n-1] = result[n-1]/2;
            int res = m%(2*n-2);
            for (int j = 0; j < res; j++){
                if (j <= n){
                    result[j]++;
                }
                if (j > n){
                    int back1 = j % n;
                    int ind = n - 1 - back1;
                    result[ind]++;
                }
            }
        }
        else if(m <= n){
            for (int i = 0; i < m; i++){
                result[i] = 1;
            }
        }

        else {
            for (int i = 0; i < n; i++){
                result[i] = 1  ;
            }
            int back2 = m % n;
            for (int i = 1; i <= back2; i++){
                int inde = n - 1 - i;
                result[inde]++;
            }
        }

        return result;
    }
};