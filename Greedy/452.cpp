class Solution {
private:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);

        int result = 1;
        for (int i = 0; i < points.size() - 1; i++){
            if (points[i][1] < points[i+1][0]) {
                result++;
            }
            else{
                points[i+1][1] = min(points[i+1][1], points[i][1]);
            }
        }
        return result;
    }
};