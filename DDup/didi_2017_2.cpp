//3 5
//n m 每个桌子最多容纳的人数n和接下来的m行
//2 4 2
//1 3
//3 5
//3 7
//5 9
//1 10

//10 + 7 + 3 = 20

#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> vec(n, 0); 
    //各背包向量
    for (int i = 0; i < n; i++) {
        cin >> vec[i]; 
    }
    //

}