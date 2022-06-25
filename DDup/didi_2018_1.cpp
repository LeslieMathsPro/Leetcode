//幂运算

#include <iostream>

using namespace std;

int main() {
    double R;
    int n;
    double result = 1;
    cin >> R >> n;
    while (n--) {
        result *= R;
    }
    cout << result << endl;
    return 0;
}