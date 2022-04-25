#include <iostream>
#include <vector>
using namespace std;

vector<int> Password(vector<int> &init, int l, int r, int iteration){
    for(int i = l; i <= r; i++){
        init[i] = iteration;
    }
    return init;
}

int main(){
    int n;
    scanf("%d", &n);
    vector<int> init(n, 0);
    int iteration;
    scanf("%d", &iteration);
    int m = iteration;
    while(iteration--){
        int l = 0, r = 0;
        scanf("%d", &l);
        scanf("%d", &r);
        init = Password(init, l, r, m - iteration);
    }
    int result = 0;
    for (int j = 0; j < init.size(); j++){
        result += j*init[j];
    }
    result %= 100000009;
    cout << result << endl;
    return 0;
}