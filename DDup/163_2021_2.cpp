#include <iostream>
#include <string>
#include <vector>
using namespace std;

void helper(vector<vector<string>> feature,  int cur, vector<int> &ans) {
    if (cur < 0) {
        for (int i = n - 1; i >= 1; i--) {
            cout << ans[i] << "-";
        }
        cout << ans[0] << endl;
        return;
    } else {
        for (string s: feature[cur]) {
            ans.push_back(s);
            helper(features, cur - 1, ans);
            ans.pop_back(); //回溯
        }
    }
}


int main() {
    int n;
    cin >> n;
    vector<vector<string>> features(n);
    for (int i = 0; i < n; i++) {
        do {
            string temp;
            cin >> temp;
            features[i].push_back(temp);
        } while (cin.get() != '\n');
    }
    vector<string> ans;
    helper (features, n - 1, ans);
}

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;
// int n;
// void helper (const vector<vector<string>>& features, int cur, vector<string>& ans) {
//     if (cur < 0) {
//         for (int i = n - 1; i >= 1; i--)
//             cout<<ans[i]<<"-";
//         cout<<ans[0]<<endl;
//         return;
//     }
//     for (auto s : features[cur]) {
//         ans.push_back(s);
//         helper(features, cur - 1, ans);
//         ans.pop_back();
//     }
// }


// int main() {

//     cin>> n;
//     vector<vector<string>> features(n);
//     for (int i = 0; i < n; i++) {
//         do{
//         string temp;
//         cin>>temp;
//         features[i].push_back(temp);
//         } while (cin.get() != '\n');
//     }
//     vector<string> ans;
//     helper(features, n - 1, ans);

// }