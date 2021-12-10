class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '[') st.push(']');
            else if (s[i] == '{') st.push('}');
            //第三种情况：遍历字符串匹配的过程中，栈已经为空，没有匹配的字符了。说明右括号没有找到对应的左括号，return false
            //第二种情况：遍历字符串匹配的过程中，发现栈里面已经没有我们要对应的字符了。return false
            else if (st.empty() || st.top() != s[i]) return false;
            else {st.pop();}
        }
        return st.empty();
    }
};