class Solution {
public:
    int minSteps(string s, string t) {
        int result = 0;
        vector<int> vec(26, 0);
        for (int i = 0; i < s.size(); ++i){
            int index1 = s[i] - 'a';
            vec[index1]++;
        }
        for (int i = 0; i < t.size(); ++i){
            int index2 = t[i] - 'a';
            vec[index2]--;
        }
        for (int j = 0; j < 26; ++j){
            if (vec[j] < 0) {
                result += -vec[j];
            } else {
                result += vec[j];
            }
        }
        return result;
    }
}; 