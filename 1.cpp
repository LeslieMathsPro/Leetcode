#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n, 0);
    vector<int> B(n, 0);
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    for (int j = 0; j < n; j++){
        cin >> B[j];
    }
    int result = 0;
    int x = 0;
    int index = 0;
    for (int i = 0; i < n; i++){
        if (A[i] != B[i]){
            for (int j = i+1; j < n; j++){
                if (A[j] == B[i]) index = j;
            }
            for (int k = index-1; k >= i; k--){
                x = A[k];
                A[k+1] = x;
            }
            A[i] = B[i];
            result++;
        }
    }
    cout << result << endl;
    return 0;
}