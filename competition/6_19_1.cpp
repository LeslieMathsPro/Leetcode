class Solution {
public:
    string greatestLetter(string s) {
        // arRAzFif
        // 26 + 32  = 58

        string A;
        char ans;

        vector<int> vec(58, 0);
        for(char c : s) {
            vec[c - 'A'] = 1;
        }

        vector<int> result(26, 0);
        for (int i = 0; i < 26; i++) {
            result[i] = (vec[i] == 1 && vec[i + 32] == 1) ? 1 : 0;
        }

        int index = -1;
        for (int i = 0; i < 26; i++) {
            if (result[i] == 1) {
                index = i;
            }
        }

        if (index == -1) {
            return A;
        }

        int def = (int)'A';
        ans = (char) (def + index);
        A = ans;


        return A;

        // vector<string> r = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y, "Z"};

        // return r[index];    
    }
};