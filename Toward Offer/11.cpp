//位运算是把数字用二进制表示之后，对每一位上0或1的运算。
//关于二进制的位运算并不是很难掌握，因为位运算总共只有五种运算:与，或，异或，左移和右移。
//左移运算符m<<n表示把m左移n位。左移n位的时候，最左边的n位将被丢弃，同时在最右边补上n个0。
//右移运算符m>>n表示把m右移n位。右移n位的时候，最右边的n位将被丢弃。但右移时处理最左边位的情形要稍微复杂一点。
//如果数字是一个无符号数值，则用0填补最左边的n位。
//如果数字是一个有符号数值，则用数字的符号位填补最左边的n位。
//也就是说如果数字原先是个正数，则右移之后在最左边补n个0；
//如果数字原先是负数，则右移之后在最左边补n个1.

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        unsigned int flag = 1;
        while (flag)
        {
            if (n & flag)
                count++;
            n = n << 1;
        }

        return count;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while (n)
        {
            ++ count;
            n = (n - 1) & n;
        }

        return count;
    }
};