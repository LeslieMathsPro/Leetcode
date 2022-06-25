//动态规划
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    int maxSum = 0;
    int curSum = 0;
    for (int i = 0; i < n; i++) {
        curSum = curSum > 0 ? curSum + vec[i] : vec[i];
        maxSum = curSum > maxSum? curSum : maxSum;
    }
    cout << maxSum << endl;
    return 0;
}