class Solution {
public:
    int distinctSequences(int n) {
        vector<int> vec(n, 0);

        //case 1 : 2 3 4 5 6
        //case 2 : 1 3 5
        //case 3 : 1 2 4 5
        //case 4 : 1 3 5
        //case 5 : 1 2 3 4 6
        //case 6 : 1 5

        vec[0] = 6;
        vec[1] = 6 + 22 - 6; //22
        vec[2] = vec[1] + 65; //22 + 65 = 87
    }
};