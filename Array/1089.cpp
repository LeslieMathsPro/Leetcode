class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int numZero = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                for (int j = arr.size() - 1; j > i + 1; j--) {
                    arr[j] = arr[j-1];
                }
                arr[i+1] = 0;
                i++;
            }
        }
        return;
    }
};