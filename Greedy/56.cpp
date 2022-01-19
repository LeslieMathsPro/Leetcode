class Solution {
private:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.size() == 0) return result;
        sort(intervals.begin(), intervals.end(), cmp); //完成按照左边界排序
        vector<int> path = {0, 0};
        for(int i = 0; i < intervals.size(); i++){
           if(intervals[i][1] >= intervals[i+1][0]){
               path[1] = max(path[1]i, ntervals[i+1][1]);
           } else {
               result.push_back(path);
               path[0] = intervals[i+1][0];
               path[1] = intervals[i+1][1];
           }
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.size() == 0) return result;
        // 排序的参数这里使用lambda表达式
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];});

        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++){
            if(result.back()[1] >= intervals[i][0]) {
                result.back()[1] = intervals[i][1];
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};