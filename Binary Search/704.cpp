//Given an array of integers nums which is sorted in ascending order, and an integer target, 
//write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
//You must write an algorithm with O(log n) runtime complexity.

 int search(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0, r = n - 1; //定义target在左闭右闭的区间里，[left, right]
    while (l <= r){//当 l == r, 区间[l,r]依然有效。所以用 <= 
        int m = l + (r - l)/2; //防止溢出, 等同与(r+l)/2;
        if (nums[m] < target){
            l = m + 1; //target 在右区间，因此用[m+1, r]
        }else if (nums[m] > target){
            r = m - 1; //target 在左区间，因此用[l, m-1]
        }else {
            return m;
        }
    }
    return -1;
 }