class Solution {
private:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        int maxCount = 1; // 记录最多有多少个分隔的区间
        sort(intervals.begin(), intervals.end(), cmp);
        int curRight = intervals[0][1]; // 记录当前右边界的值
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] >= curRight) {
                maxCount++;
                curRight = intervals[i][1];
            }
        }
        int result;
        result = intervals.size() - maxCount;
        return result;
    }
};