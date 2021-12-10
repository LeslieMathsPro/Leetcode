class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(),s.begin()+n);
        reverse(s.begin()+n+1, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};