class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        string builder;
        //循环相加两个字符串相同长度的低位数部分
        while (i >= 0 && j >= 0) {
            int sum = carry;
            sum += a.at(i--) - '0';
            sum += b.at(j--) - '0';
            carry = sum / 2; 
            builder+=to_string((sum%2)); 
        }

        //如果a还没有遍历完(a串比b串长)，则继续遍历添加a的剩余部分
        while (i >= 0){
            int sum = carry + a.at(i--) -'0';
            carry = sum/2;
            builder+=to_string((sum % 2));
        }

        //如果b还没有遍历完(b串比a串长), 则继续遍历添加b的剩余部分
        while (j >= 0) {
            int sum = carry + b.at(j--) - '0';
            carry = sum / 2;
            builder+=to_string(sum % 2);
        }

        //如果 carry 不等于0 还有个进位数没加进去，需要补充
        if (carry == 1) {
            builder+=to_string(carry);
        }

        //反转字符串获得正常结果
        reverse(builder.begin(),builder.end());
        return builder;
    }
};