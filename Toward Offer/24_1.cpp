class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        vector<int> sub;
        int root = INT_MAX;
        for (auto i = postorder.rbegin(); i < postorder.rend(); ++i) //中序的逆序遍历
        {
            if (*i > root) return false;
            while (sub.size() && *i < sub.back()) //切换遍历结点，清除上次遍历数据，出栈
                root = sub.back();
                sub.pop_back();
            sub.push_back(*i); // 单调递增逻辑，压栈
        }
        return true;
    }
};