class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        for (int i = 0; i < magazine.size(); i++){
            //通过recode数据记录，magazine里各个字符出现的次数
            record[magazine[i] - 'a']++;
        }
        for (int j = 0; j < ransomNote.size(); j++){
            //遍历ransomNote，在record里对应的字符串做--操作
            record[ransomNote[j] - 'a']--;
            //如果小于0则说明出现ransomNote里出现的字符，而magazine里面没有
            if (record[ransomNote[j]-'a']<0){
                return false;
            }
        }
        return true;
    }
};