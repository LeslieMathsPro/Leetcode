//质数因子 
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int main() {
    long n;
    cin >> n;
    for (long i = 2; i <= sqrt(n); i++) {
        while (n%i == 0) {
            cout << i << ' ';
            n /= i;
        }
    }
    if (n!=1) cout << n << ' ';
    return 0;
}