class Solution {
public:
    int percentageLetter(string s, char letter) {
        int numbre = s.size();
        int count = 0;
        for (char si : s) {
            if (si - letter[0] == 0) count++;
        }
        int result = count / numbre;
        return result;
    }
};