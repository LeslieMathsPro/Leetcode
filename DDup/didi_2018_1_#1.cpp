#include <iostream>

using namespace std;

bool isUglyNumber(int val) {
    //只包含因子2，3和5的数被称为丑数
    while (val%5 == 0) {
        val /= 5;
    }
    while (val%3 == 0) {
        val /=3;
    }
    while (val%2 == 0) {
        val /=2;
    }
    return val == 1;
}

int main() {
    int n;
    cin >> n;
    //寻找第n个数
    int val = 0;
    while (n != 0) {
        val++;
        if (isUglyNumber(val) == true) {
            n--;
        }
    }
    cout << val << endl;
    return 0;
}