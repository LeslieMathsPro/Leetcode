//动态规划是由前一个状态推导出来的，而贪心是局部直接选最优的
class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};