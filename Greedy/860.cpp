class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for (int bill : bills){
            //情况1
            if (bill == 5) five++;
            //情况2
            if (bill == 10) {
                if (five == 0) {
                    return false;
                }
                five--;
                ten++;
            }
            //情况3
            if (bill == 20){
                if (ten > 0 && five > 0){
                    ten--;
                    five--;
                    twenty++;
                }else if (five >= 3){
                    five -= 3;
                    twenty++;
                }else {return false;}
            }
        }
        return true;
    }
};