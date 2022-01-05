class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @param k int整型 
     * @return string字符串
     */
    string NS_String(string s, int k) {
        // write code here
        if (k == 0) return s;
        string dex = "abcdefghijklmnopqrstuvwxyz";
        for (int i = 1; i =< k; i++){
            for (int j = 0; j < s.size(); j++){
                if (s[j] == dex[i - 1]){
                    s.erase(j,1);
                }
            }
        }
        return s;
    }
};