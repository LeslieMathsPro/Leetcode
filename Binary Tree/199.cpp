/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        vector<int> result;
        while (!que.empty())
        {
            int last = 0;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* Node = que.front();
                que.pop();
                last = Node->val;
                if (Node->left) que.push(Node->left);
                if (Node->right) que.push(Node->right);
            }
            result.push_back(last);
        }
        return result;
    }
};