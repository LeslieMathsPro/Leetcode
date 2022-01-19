class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candyVec(ratings.size(), 1); 
        // 从前向后
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
        }
        // 从后向前
        for (int i = ratings.size() - 1; i >= 1; i--) {
            if (rating[i - 1] > rating[i]) candyVec[i - 1] = max(candyVec[i - 1], candyVec[i] + 1);
        }
        int sum;
        for (int i = 0; i < ratings.size(); i++){
            sum += ratings[i];
        }
        return sum;
    }
};