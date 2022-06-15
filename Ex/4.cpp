#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += vec[i];
    }
    int result = 0;
    int left = 0, right = n - 1;
    while (n != 0) {
        if (sum/vec[left] < sum/vec[right]) {
            result += sum/vec[right];
            sum -= vec[right];
            right--;
        } else if (sum/vec[left] > sum/vec[right]) {
            result += sum/vec[left];
            sum -= vec[left];
            left++;
        } else {
            if (vec[left] > vec[right]) {
                result += sum/vec[left];
                sum -= vec[left];
                left++;
            } else {
                result += sum/vec[right];
                sum -= vec[right];
                right--;
            }
        }
        n--;
    }
    cout << result << endl;
    return 0;
}