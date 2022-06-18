#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    int key, value;
    map<int, int, less<int>> pairs;
    for (int i = 0; i < n; i++) {
        cin >> key >> value;
        if(pairs.count(key) == 0) 
        {
            pairs.insert(make_pair(key, value));
        } else {
            pairs[key] += value;
        }
    }
    for (auto it = pairs.begin(); it != pairs.end(); it++) 
    {
        cout << it->first << ' ' << it->second << endl;
    }

    return 0;

}