#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    vector<int> result(n, 0);
    for (int i = 0; i < n; i++) {
        unordered_set<int> set;
        set.insert(vec[0]); //
        result[i] = 1;
        for (int j = 1; j <= i; j++) {
            if (i%j == 0 && set.count(vec[j]) == 0) {
                set.insert(vec[j]);
                result[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    return 0;
}