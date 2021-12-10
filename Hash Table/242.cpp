//数组其实就是一个简单的哈希表， 而且这里只有小写字母，那么可以定义一个数组，来记录字符串s中字符出现的次数。

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++){
            record[s[i] - 'a']++;
        }
        for (int j = 0; j < t.size(); j++){
            record[t[j] - 'a']--;
        }

        for (int i = 0; i < 26; i++){
            if (record[i] != 0){
                return false;
            }
        }
        return true;
    }
};