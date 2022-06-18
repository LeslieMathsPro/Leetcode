#include <iostream>
#include <vector>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    vector<int> vec(200, 0);

    for (char i : a) {
        vec[i - '0']++;
    }

    for (char j : b) {
        vec[j - '0']--;
    }

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] != 0) {
            cout << "false" << endl;
            return 0;
        }
    }

    cout << "true" << endl;
    return 0;
}
