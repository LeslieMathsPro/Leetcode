class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> Nums1, Nums2;
        vector<int> interm1(3, 0);
        vector<int> interm2(3, 0);
        long long result;
        for (int i = 0; i < nums1.size() - 2; i++){
            for(int j = i + 1; j < nums1.size() - 1; j++){
                for(int k = j + 1; k < nums1.size(); k++){
                    interm1[0] = nums1[i];
                    interm1[1] = nums1[j];
                    interm1[2] = nums1[k];
                    Nums1.push_back(interm1);
                }
            }
        }
        for (int i = 0; i < nums2.size() - 2; i++){
            for(int j = i + 1; j < nums2.size() - 1; j++){
                for(int k = j + 1; k < nums2.size(); k++){
                    interm2[0] = nums2[i];
                    interm2[1] = nums2[j];
                    interm2[2] = nums2[k];
                    Nums2.push_back(interm2);
                }
            }
        }
        for (int i = 0; i < Nums1.size(); i++){
            for (int j = 0; j < Nums2.size(); j++){
                if (Nums1[i] == Nums2[j]){
                    result++;
                    break;
                }
            }
        }
        return result;
    }
};