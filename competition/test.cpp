
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> a[4, 0, 1];
    vector<int> b[4, 0 ,2];
    int result = 1;
    if (a == b)
    {   
        result = 0;
    }
    cout << result << endl;
}