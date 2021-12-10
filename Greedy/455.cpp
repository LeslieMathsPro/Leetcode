class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //g是小孩胃口数组，s是饼干尺寸数组  
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1;
        int result = 0;
        for (int i = g.size() - 1; i >= 0; i--) {
            if (g[i]<=s[index]){
                result++;
                index--;
            }
        }
        return result;
    }
};