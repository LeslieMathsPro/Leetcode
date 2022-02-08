class Solution {
public:
    long long smallestNumber(long long num) {
        vector<int> P_array;
        vector<int> N_array;
        long long result = 0;
        if (num > 0) {
            while (num != 0) 
            {
                int value = num%10;
                P_array.push_back(value);
                num = num/10;
            }
            sort(P_array.begin(),P_array.end());
            if (P_array[0] != 0){
                for (int i = 0; i < P_array.size(); ++i) {
                    result += P_array[i]*(pow(10, P_array.size() - i - 1));
                }
            } else {
                for (int i = 0; i < P_array.size(); ++i) {
                    if(P_array[i] > 0){
                        result += P_array[i]*(pow(10, P_array.size() - 1));
                        for (int j = i + 1; j < P_array.size(); ++j) {
                            result += P_array[j]*(pow(10, P_array.size() - j - 1));
                        }
                        break;
                    }
                }
            }
        } else {
            num = -num;
            while (num != 0)
            {
                int value = num%10;
                N_array.push_back(value);
                num = num/10;
            }
            sort(N_array.begin(), N_array.end());
            reverse(N_array.begin(), N_array.end());
            for (int i = 0; i < N_array.size(); ++i){
                result += N_array[i]*(pow(10, N_array.size() - i - 1));
            }
            result = -result;
        }

        return result;
    }
};