#include <iostream>
using namespace std;

int solve(int arr[], int n, int m) {
  // 请添加具体实现
  int result = 0;
  for (int i = 0; i < n; i++){
      for (int j = i + 1; j < n; j++){
          if(arr[i] + arr[j] == m) result++;
      }
  }
  return result;
}

int main(){
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 10;
    int m = 7;
    int out = solve(arr, n, m);
    cout << out << endl;
    return 0;
}