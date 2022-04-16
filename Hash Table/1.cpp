// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         std::unordered_map<int,int> map;
//         for (int i = 0; i < nums.size(); i++){
//             auto iter = map.find(target - nums[i]);
//             if (iter != map.end()){
//                 return {iter -> second, i};
//             }
//             map.insert(pair<int,int> (nums[i], i));
//         } 
//         return {};
//     }
// };

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> result;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++){
        map.insert(pair<int, int> (nums[i], i));
    }
    for (int j = 0; j < nums.size(); j++){
        auto iter = map.find(target - nums[j]);

        if(iter != map.end()){
            if(iter->second != j){
                result.push_back(j);
                result.push_back(iter->second);
                break;
            } else {
                continue;
            }
        }
    }
    return result;
}
int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
}