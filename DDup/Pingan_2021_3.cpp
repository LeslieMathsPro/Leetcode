//分糖果

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }

    //求和
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += vec[i];
    }
    if (sum % n != 0) cout << "-1" << endl;
    int average = sum/n;

    //考虑 vec[i] - average的值能不能被2整除
    for (int i = 0; i < n; i++){
        if ((vec[i] - average) % 2) {
            cout << "-1" << endl;
            break;
        }
    }

    //计算次数
    int count = 0;
    int res = 0;
    for (int i = 0; i < n; i++){
        res += abs(vec[i] - average);
    }
    int temp = res/2;
    count = temp%2==0? temp/2 : -1;
    cout << count << endl;
    return 0;
}