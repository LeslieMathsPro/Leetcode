#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> list = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(int i = 0; i < 5; i++){
        cout << i << endl;
    }
    for(int j = 5; j < list.size(); j++){
        cout << j << endl;
    }
    return 0;
}