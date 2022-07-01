#include <iostream>
#include <math.h>

using namespace std;

long maxDivit(long x, long y) {
    long maxdivit = 1;
    for (int i = 1; i <= y/2; i++) {
        if (y%i == 0 && x%i == 0) {
            maxdivit = i > maxdivit ? i : maxdivit;
        }
    }
    return maxdivit;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long x = 0;
        long y = 0;
        long c = 0;
        long result = 0;
        cin >> x >> y;

        if (x < y) {
            c = x;
            x = y;
            y = c;
        }

        if (x%y == 0) {
            result = x/y;
            if (result % 2 == 1) {
                cout << "A" << endl;
            } else {
                cout << "B" << endl;
            }
        } else {
            long maxdivit = 0;
            maxdivit = maxDivit(x, y);
            result = x/maxdivit;
            if (result % 2 == 1) {
                cout << "A" << endl;
            } else {
                cout << "B" << endl;
            }
        }
    }
    return 0;
}