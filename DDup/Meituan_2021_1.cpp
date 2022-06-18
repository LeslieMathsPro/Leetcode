#include <iostream>

int main() {
    int n;
    std::cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }

    vector<int> temp(vec);
    sort(temp.begin(), temp.end());
    reverse(temp.begin(), temp.end());

    int result = 0;
    
}