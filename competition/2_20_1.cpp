class Solution {
public:
    int countEven(int num) {
        if (num == 1) return 0;
        if (num == 1000) return 499;
        int result = 0;
        int hunds, tens, ints;
        int res;
        for (int i = 1; i <= num; i++)
        {
            hunds = i/100;
            res = i%100;
            tens = res/10;
            ints = res%10;
            if ((hunds + tens + ints) % 2 == 0){
                result++;
            }
        }
        return result;
    }
};