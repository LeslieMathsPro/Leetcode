class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex){
        result.push_back(path); //收集子集，要放在终止添加上吗
        if (startIndex >= nums.size()) return; //其实可以不需要加上终止条件，因为当startIndex大于等于nums的size，循环本身也结束了
        for(int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};