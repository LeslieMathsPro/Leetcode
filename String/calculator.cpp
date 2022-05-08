class Solution {
public:
    int calculate(string s) {
        char prev_op = '+';
        s.push_back('x'); //哨兵字符
        int num1 = 0, num2 = 0, num = 0;
        for (char c : s)
        {
            if (c == ' ') continue;
            else if (isdigit(c)) num = num*10 + (c - '0');
            else {
                //数字已经扫描完了
                if (prev_op == '+' || prev_op == '-')
                {
                    num1 += num2;
                    num2 = prev_op == '+' ? num:-num;
                } else if (prev_op == '*') num2 *= num;
                else num2 /= num;
                prev_op = c;
                num = 0;
            }
        }
        return num1 + num2;
    }
};