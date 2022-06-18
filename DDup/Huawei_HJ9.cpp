// 提取不重复的整数

#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    int result = 0;

    set<int> s;
    while (n != 0) {
        int m = n%10;
        if (!s.count(m)) {
            s.insert(m);
            result = result*10 + m;
        }
    }
    cout << result << endl;
    return 0;
}