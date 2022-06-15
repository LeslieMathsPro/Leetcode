#include <iostream>

using namespace std;

int main() {
    int T; //一共有T组数据
    cin >> T;
    int n; //n个人排队买票
    int minTime; //最小时间
    while (T--) {
        cin >> n;   
        vector<int> indTime(2000, 0);
        for (int i = 0; i < n; i++) {
            cin >> indTime[i];
        }
        vector<int> douTime(2000, 0);
        for (int i = 0; i < n - 1; i++) {
            cin >> douTime[i];
        }
        minTime = 0;
        vector<int> dp(n, 0);
        dp[0] = indTime[0];
        dp[1] = min(indTime[0] + indTime[1], douTime[0]);
        for (int i = 2; i < n; i++) {
            dp[i] = 
        }
    }
}