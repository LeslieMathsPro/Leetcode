class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        int n = time.size();
        long long iterMax = totalTrips*time[0];
        long long i = time[0];
        for (; i <= iterMax; i++){
            int sum = 0;
            for (int j = 0; j < n; j++){
                if(i < time[j]){
                    break;
                }
                int times = i/time[j];
                sum += times;
            }
            if(sum >= totalTrips){
                break;
            }
        }
        return i;
    }
};