class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> result;
        if (time == 0) {
            for (int i = 0; i < n; i++){
                result.push_back(i);
            }
        }
        if (time > n) {
            return result;
        }
        for (int i = time; i < security.size() - time; i++)
        {
            for (int j = 0; j <= time; )
            {
                if (security[i] <= security[i-j] && security[i]<= security[i+j]){
                    j++;
                }
                else {
                    break;
                }

                if (j == time) result.push_back(i);
            }
        }
        return result;
    }
};