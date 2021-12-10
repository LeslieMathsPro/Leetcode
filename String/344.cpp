class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.length() - 1;
        while (left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    return s;
};