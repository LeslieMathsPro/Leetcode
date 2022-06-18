//字符个数统计 
#include <iostream>
#include <string>

using namespace std;

int main() {
    vector<int> vec(128, 0);
    string s;
    cin >> s;
    for (char c:s) {
        int i = (int)c;
        vec[i] = 1;
    }
    int result = 0;
    for (int i = 0; i < vec.size(); ++i) {
        result += vec[i];
    }
    cout << result << endl;
    return 0;
}