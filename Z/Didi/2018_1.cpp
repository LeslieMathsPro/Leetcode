#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec;
    cin >> vec;
    int i;
    cin >> i;
    sort(vec.begin(), vec.end());
    cout << vec[i-1];
    return 0;
}