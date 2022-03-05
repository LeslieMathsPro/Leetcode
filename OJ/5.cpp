#include <iostream>
using namespace std;

int main(){
    int line;
    cin >> line;
    while (line--){
        int n;
        cin >> n;
        int val;
        int sum = 0;
        for (int i = 0; i < n; i++){
            cin >> val;
            sum += val;
        }
        cout << sum << endl;
    }
    return 0;
}