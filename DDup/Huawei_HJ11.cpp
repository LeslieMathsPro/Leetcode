// 数字颠倒 
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    while (n) {
        int c = n % 10;
        s += to_string(c);
        n /= 10;
    }

    cout << s << endl;
    return 0;
}