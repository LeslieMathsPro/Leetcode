class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex){
        if (path.size() > 1) result.push_back(path);
        int uset[201] = {0}; // 这里使用数组来进行去重操作，题目说范围是[-100, 100]
        for (int i = startIndex; i < nums.size(); i++){
            if ((!path.empty() && nums[i] < path.back()) || uset[nums[i] + 100] == 1){
                continue;
            }
            uset[nums[i] + 100] = 1;
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};