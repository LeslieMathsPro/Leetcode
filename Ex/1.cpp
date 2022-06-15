//两数之和 vector<int> nums, int k, output pair<int, int> i1, i2

#include<iostream>
#include<vector>

using namespace std;

vector<int> twoSum(vector<int> nums, int k) {
        vector<int> result(2, 0);
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == k) {
                    result[0] = i;
                    result[1] = j;
                }
            }
        }
        return result;
    }

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 9;
    vector<int> ans;
    ans = twoSum(nums, k);
    cout << ans[0] << ' ' << ans[1] << endl;
    return 0;
}