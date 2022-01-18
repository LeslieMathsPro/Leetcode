class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int curDistance = 0; //当前覆盖的最远距离下标
        int ans = 0;         //记录最少步数
        int nextDistance = 0;//下一步覆盖的最远距离下标
        for (int i = 0; i < nums.size(); i++){
           nextDistance = max(nextDistance, i + nums[i]); //更新下一步覆盖最远距离下标
           if(i == curDistance)  { //遇到当前覆盖最远距离下标
                if (curDistance != nums.size() - 1) {
                    ans++;          //需要向下走一步
                    curDistance = nextDistance; //更新当前覆盖最远距离下标
                    if (nextDistance >= nums.size() - 1) break;
                } else break;
           }
        } 
        return ans;
    }
};