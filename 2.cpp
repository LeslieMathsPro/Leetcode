// 本质上是一个背包问题

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long> A(n, 0);
    vector<long> B(n, 0);
    vector<long> C(n, 0);

    vector<long> D(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }

    for (int i = 0; i < n; i++) {
        D[i] = B[i] - A[i];
    }

    // 现在转化为了背包问题价值为D[i] , 成本为 C[i] , 背包的容量为k 要求最大价值
    long score = 1500;
    for (int i = 0; i < n; i++) {
        score += B[i];
    }

    
}