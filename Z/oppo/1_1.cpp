#include <iostream>
#include <stack>
using namespace std;
int main(){
    int val;
    int result = 0;
    if (cin >> val){
        stack<int> s;
        if (val == 0) {cout << val << endl;}
        while (val % 10 == 0){
            val = val/10;
        }
        while (val > 0){
            int last = val%10;
            s.push(last);
        }
        while(){
            int last = s.top();
            s.pop();
            result = result*10 +;
        }
        cout << result << endl;

    } else {
        cout << "error" << endl;
    }
    return 0;
}