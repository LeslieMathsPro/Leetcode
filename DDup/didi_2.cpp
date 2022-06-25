// 输入一个字符串
// 然后进行n次替换
// 每次将字符串里的 str1 替换成 str2
// 最后输出被替换n次的字符串

// 例如 输入
// abcabc
// 2
// bca abb
// bbb aac
// 输出
// aaaacc

#include <iostream>

using namespace std;

int main() {
    string s;
    int n;
    cin >> s;
    cin >> n;
    string s1;
    string s2;
    while (n--) {
        cin >> s1;
        cin >> s2;
        int m = s1.size();
        for (int i = 0; i < s.size() - m; i++) {
            for (int j = i; j < i + m; j++) {
                if (s[j] != s1[j - i]) {
                    break;
                }
                if (j - i == m-1) {
                    
                }
            }
        }
    }
}