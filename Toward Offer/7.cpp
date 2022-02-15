//树 逻辑: 除了根结点之外每个结点只有一个父结点，根结点没有父结点。
//除了叶结点之外所有结点都有一个或者多个子结点，叶结点没有子结点。
//父结点与子结点之间用指针链接。

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<int, int> index;

public:
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right)
    {
        if (preorder_left > preorder_right) {
            return nullptr;
        }
        int preorder_root = preorder_left;
        int inorder_root = index[preorder[preorder_root]];
        // 建立根节点
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        // 得到左子树中的节点个数
        int size_left_subtree = inorder_root - inorder_left;
        // 递归地构造左子树，并连接到根结点
        root->left = myBuildTree(preorder, inorder, preorder_left+1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);

        root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right );

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        //构造哈希映射，帮助我们快速定位根结点
        for (int i = 0; i < n; ++i)
        {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};