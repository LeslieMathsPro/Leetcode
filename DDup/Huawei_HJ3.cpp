// 明明的随机数

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec(n, 0);
    
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    cout << vec[0] << endl;
    for(int i = 1; i < n; i++) {
        if (vec[i] == vec[i-1]) continue;
        cout << vec[i] << endl;
    }

    return 0;
}