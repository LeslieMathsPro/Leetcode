class Solution {
public:
    int countAsterisks(string s) {
        int index = 0;
        int numL = 0;
        int count = 0;
        while (index < s.size()) {
            if (s[index] == '|') {
                numL++;
            }
            if (numL%2 == 0) {
                if (s[index] == '*') {
                    count++;
                }
            }
            index++;
        }
        return count;
    }
};