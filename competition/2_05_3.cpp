class Solution {
public:
    int countTime(int startAt, int moveCost, int pushCost, int min, int sec)
    {
        int Time = 0;
        if (min >= 10){
            int min_1 = min/10;
            int min_2 = min%10;
            if (min_1 == startAt){
                Time += pushCost;
            } else {
                Time += moveCost;
                Time += pushCost;
            }
            if (min_1 == min_2){
                Time += pushCost;
            } else {
                Time += moveCost;
                Time += pushCost;
            }
            int sec_1 = sec/10;
            int sec_2 = sec%10;
            if (sec_1 == min_2){
                Time += pushCost;
            } else {
                Time += moveCost;
                Time += pushCost;
            }
            if (sec_1 == sec_2){
                Time += pushCost;
            } else {
                Time += moveCost;
                Time += pushCost;
            }
        } else if(min != 0) {
            if (startAt == min){
                Time += pushCost;
            } else {
                Time += moveCost;
                Time += pushCost;
            }
            int sec_1 = sec/10;
            int sec_2 = sec%10;
            if (min == sec_1){
                Time += pushCost;
            } else {
                Time += moveCost;
                Time += pushCost;
            }
            if (sec_1 == sec_2){
                Time += pushCost;
            }else {
                Time += moveCost;
                Time += pushCost;
            }
        } else {
            int sec_1 = sec/10;
            int sec_2 = sec%10;
            if (sec_1 != 0) {
                if (sec_1 == startAt){
                    Time += pushCost;
                } else {
                    Time += moveCost;
                    Time += pushCost;
                } 
                if (sec_1 == sec_2) {
                    Time += pushCost;
                } else {
                    Time += moveCost;
                    Time += pushCost;
                }
            } else if(sec_2 != 0) {
                if (sec_2 == startAt){
                    Time += pushCost;
                } else {
                    Time += moveCost;
                    Time += pushCost;
                }
            } else {
                Time += 0;
            }
        }
        return Time;
    }
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int min = targetSeconds/60;
        int sec = targetSeconds%60;

        int result1 = INT_MAX;
        int result2 = INT_MAX;
        int result = INT_MAX;

        result1 = countTime(startAt, moveCost, pushCost, min, sec);

        if (sec <= 39){
            int min_p = min-1; //min要大于等于1
            int sec_p = sec+60;
            result2 = countTime(startAt, moveCost, pushCost, min_p, sec_p);
        }

        if (sec > 39){
            return result1;
        } else {
            if (result1 <= result2) {
                return result1;
            } else {
                return result2;
            }
        }
    }
};