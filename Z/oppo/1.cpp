#include <iostream>

using namespace std;
int main(){
    int val;
    if (cin >> val){
        int result; 
        if (val == 0){
            cout << val << endl;
        }
        while (val % 10 == 0){ //消除输入的末尾0
            val /= 10;
        }
        while (val > 0){
            int last = val%10;
            result = result*10 + last;
            val /= 10;
        }
        cout << result << endl;
    } else {
        cout << "error" << endl;
    }
    return 0;
}