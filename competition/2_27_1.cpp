// class Solution {
// public:
//     int prefixCount(vector<string>& words, string pref) {
//         int n = pref.size();
//         int result = 0;
//         for (auto s:words){
//             if (strcmp(s.substr(0,n), pref) == 0){
//                 result++;
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int result = 0;
        int n = pref.size();
        for (string s:words){
            for (int i = 0; i < n; ++i){
                if (s[i] != pref[i]){
                    break;
                }
                if (i == n-1){
                    result++;
                }
            }
        }
        return result;
    }
};