#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

string decodeMessage(string key, string message) {
  string ans;
  unordered_map<char, char> map;
  string rules = "abcdefghijklmnopqrstuvwxyz";
  int k = 0;
  for (int i = 0; i < key.size(); ++i) {
    if (key[i] == ' ') continue;
    else if (!map.count(key[i])) {
        map.insert(make_pair(key[i], rules[k]));
        k++;
    } else {
        continue;
    }
  }
  map.insert(make_pair(' ', ' '));
  for (int j = 0; j < message.size(); ++j) {
    ans += map[message[j]];
  }
  return ans;
}

int main(){
    string ans = decodeMessage("the quick brown fox jumps over the lazy dog", "vkbs bs t suepuv");
    for (int i = 0 ; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}