#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(){
    int num;
    cin >> num;
    vector<string> strs(num);
    while (--num > 0){
        cin >> strs[num];
    }
    sort(strs.begin(), strs.end());
    num = strs.size() - 1;
    for (int i = 0; i < num; ++i){
        cout << strs[i] << ' ';
    }
    cout << strs[num] << '\n';
    return 0;
}