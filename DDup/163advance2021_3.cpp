#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main() {
    string s;
    cin >> s;
    stack<char> st;
    st.push(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != st.top()) {
            st.push(s[i]);
        } else {
            st.pop();
        }
    }
    bool addToEnd = st.top() == s[s.size()-1]; //if true, 剩余的部分应该加到原string头部；否则，加到尾部
    string res;
    while(!st.empty()) {
       res += st.top();
       st.pop();
    }
    if (addToEnd) {
        s = res + s;
    } else {
        s = s + res;
    }
    cout << s << endl;
    return 0;
}