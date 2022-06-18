#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> vec;
    while (n!=0) {
        vec.push_back(n%10);
        n = n/10;
    }
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++){
        if (vec[i] == 1) dp[0]+=2;
        else dp[0]
    }
    for (int j = 1; j < n; j++){
        if (vec[j] == 1){
            
        }
    }
}