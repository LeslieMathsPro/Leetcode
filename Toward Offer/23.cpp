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
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        deque<TreeNode*> dequeTreeNode;
        dequeTreeNode.push_back(root);

        while(dequeTreeNode.size())
        {
            TreeNode* pNode = dequeTreeNode.front();
            result.push_back(pNode->val);
            dequeTreeNode.pop_front();

            if (pNode->left)
                dequeTreeNode.push_back(pNode->left);

            if (pNode->right)
                dequeTreeNode.push_back(pNode->right);
        }

        return result;
    }
};