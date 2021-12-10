class Solution {
public:
    string removeDuplicates(string s) {
        stact<char> st;
        for (auto elem: s){
            if (st.empty() || elem != st.top()){
                st.push(elem);
            } else {
                st.pop();
            }
        }
        string result = "";
        while (!st.empty()){ // 将栈的元素放到result字符串进行汇总 
            result += st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};