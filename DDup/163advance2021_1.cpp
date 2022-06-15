//类似于碰撞问题
#include <iostream>
#include <vector>
using namespace std;

void valueToWaste(vector<int> vec)
{
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    int res = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        
    }

    
}

int main() {
    int T;
    cin >> T;
    int n;
    cin >> n;
    vector<int> vec;
    while(T--) {
        vec.clear();
        while(n--) {
            int k;
            cin >> k;
            vec.push_back(k);
        }
        valueToWaste(vec);
    }
    return 0;
}