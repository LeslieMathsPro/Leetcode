#include <iostream>
#include <vector>
using namespace std;

vector<int> findBuilding(vector<int>& heights) {
        // write code here
        int n = heights.size();
        vector<int> slight(n, 0);
        for (int i = 0; i < n; i++){
            int j = i;
            int k = i;
            int count;
            int preMax = 0, aftMax = 0;
            if(i == 0) count = 2;
            else if(i == n-1) count = 2;
            else count = 3;
            while(i - 1 > 0) {
                if(preMax < heights[i-2]) count++;
                preMax = max(preMax, heights[i-2]);
                i--;
            }
            while(i + 2 < n) {
                if(aftMax > heights[i+2]) count++;
                aftMax = max(aftMax, heights[i+2]);
                i++;
            }
            
            slight[i] = count;
        }
    return slight;
}

int main(){
    vector<int> heights = {5,3,8,3,2,5};
    vector<int> slight = findBuilding(heights);
    for (int i = 0; i < slight.size(); i++){
        cout << slight[i] << endl;
    }
    return 0;
}