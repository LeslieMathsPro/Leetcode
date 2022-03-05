#include <iostream>
using namespace std;

int main(){
    int num;
    int sum = 0;
    while (cin >> num){
        sum += num;
        if (cin.get() == '\n'){ //这里使用使用cin.get()，可以只读一个字符，空白字符和换行符都可以读进去。
            cout << sum << endl;
            sum = 0;
        }
    }
    return 0;
}