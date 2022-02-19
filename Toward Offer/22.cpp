class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int t = 0;
        for(int x:pushed)
        {
            s.push(x);
            while(!s.empty && popped[t] == s.top()){
                s.pop();
                t++;
            }
        }
        return s.empty();
    }
};