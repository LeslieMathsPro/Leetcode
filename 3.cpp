#include <iostream>
#include <string>
#include <algorithm>
#include <assert.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    string result; 
    int n = s.size();
    //3*[a2*[c]]
    for (int i = n - 1; i >= 0;){ //从后向前遍历
        if (s[i] == ']') {
            i--;
            continue;
        } else if (s[i] >= 'a' && s[i] <= 'z'){
            result = result + s[i];
            i--;
        } else if (s[i]=='[') {
            assert(--i >= 0 && s[i] == '*');
            assert(--i >= 0 && s[i] >= '0' && s[i] <= '9');
            int num = 0;
            int fac = 1;
            while (i >= 0 && s[i] >= '0' && s[i] <= '9'){
                num = num + (s[i] - '0')*fac;
                fac *= 10;
                i--;
            }
            string tmp; 
            for (int i = 0; i < num; i++){
                tmp += result;
            }
            result = tmp;
            reverse(result.begin(), result.end());
        }
    }
    cout << result << endl;
    return 0;
}