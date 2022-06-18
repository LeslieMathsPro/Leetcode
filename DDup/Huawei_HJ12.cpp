// 字符串反转
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    string c;
    int n = s.size();
    for (int i = n-1; i >= 0; i--) {
        c += s[i];
    }

    cout << c << endl;
    return 0;
}