//  句子逆序 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> vec;
    string s;
    while (cin >> s) {
        vec.push_back(s);
    }
    for (int i = vec.size() - 1; i >= 0; i--) {
        cout << vec[i] << ' ';
    }

    return 0;
}