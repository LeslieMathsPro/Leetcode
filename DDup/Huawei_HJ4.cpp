//字符串分隔 ?

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int iteration = n/8;
    int res = n%8;
    int i = 0;
    if (iteration == 0) 
    {
        string r = s;
        int add = 8 - res;
        while (add--) {
            r += '0';
        }
        cout << r << endl;
    } else {
        for (i = 0; i < iteration; i++) {
            string r = s.substr(8*i, 8);
            cout << r << endl;
        } 
        if (add != 0) {
            string r = s.substr(8*(i+1));
            while (add--) {
                r += '0';
            }
            cout << r << endl;
        }
    }
    return 0;
}