class Solution {
public:
    string replaceSpace(string s) {
        if(s.empty()) return s;
        //originalLength为字符串string的实际长度
        int originalLength = 0;
        int numberOfBlank = 0;
        int i = 0;
        while (s[i] != '\0')
        {
            ++originalLength;

            if (s[i] == ' ')
                ++numberOfBlank;

            ++i;
        }
        //newLength 为把空格替换成'%20'之后的长度
        int newLength = originalLength + 2 * numberOfBlank;
        
        int indexOfOriginal = originalLength;
        int indexOfNew = newLength;
        while(indexOfOriginal >= 0 &&indexOfNew > indexOfOriginal)
        {
            if(s[indexOfOriginal] == ' ')
            {
                s[indexOfNew--] = '0';
                s[indexOfNew--] = '2';
                s[indexOfNew--] = '%';
            }
            else
            {
                s[indexOfNew--] = s[indexOfOriginal];
            }

            --indexOfOriginal;
        }
        return s;
    }
};