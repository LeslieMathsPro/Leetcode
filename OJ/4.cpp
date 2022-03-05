#include <iostream>
using namespace std;

int main(){
    int n;
    while (cin >> n && n != 0){
        int sum = 0;
        int val;
        for (int i = 0; i < n; i++){
            cin >> val;
            sum += val;
        }
        cout << sum << endl;
    }
    return 0;
}