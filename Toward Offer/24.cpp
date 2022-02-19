class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.size() == 0) return false;

        int n = postorder.size();
        int root = postorder[n - 1];

        //在二叉搜索树中左子树的结点小于根结点
        //int i = 0;
        auto i = postorder.begin();
        for (; i != postorder.end() - 1; ++i)
        {
            if (*i > root)
                break;
        }

        //在二叉搜索树中右子树的结点小于根结点
        auto j = i;
        for (; j != postorder.end() - 1; ++j)
        {
            if(*j < root)
                return false;
        }

        //判断左子树是不是二叉搜索树
        bool left = true;
        auto b = postorder.begin();
        auto e = i;
        vector<int> leftVec(b, e);
        if (i > 0)
            left = verifyPostorder(leftVec);
        
        //判断右子树是不是二叉搜索树
        bool right = true;
        auto bg = i + 1;
        auto en = postorder.end() - 1;
        vector<int> rightVec(bg, en);
        if (i != postorder.end())
            right = verifyPostorder(rightVec);

        return (left && right);
    }
};