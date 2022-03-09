#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> vec(n, 0);

    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }

    int maxpre = 0;
    int result = vec[0];
    for (int i = 0; i < n; i++){
        maxpre = max(maxpre + vec[i], vec[i]);
        result = max(result, maxpre);
    }
    cout << result << endl;
    return 0;
}