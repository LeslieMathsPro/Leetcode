#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++){
       cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int p = 1; //初始输出伤害为1
    int t = 0; //t为回合次数
    for (int j = 0; j < n; j++) {
        while (vec[j] > 0) {
            vec[j] -= p;
            t++;
        }
        p++;
    }
    cout << t << endl;
    return 0;
}