class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        map <char, int> luomob = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        }; //初始化哈希表
        for(int i = 0; i < s.size(); i++)
        {
            if (luomob[s[i] < luomob[s[i+1])
            {
                result -= luomob[s[i]];
            } else {
                result += luomob[s[i]];
            }
        } 
        return result;
    }
};