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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        vector<int> res;
        while(!que.empty()) {
            int size = que.size();
            int maxValue = INT_MIN;
            while(size--) {
                TreeNode* Node = que.front();
                que.pop();
                maxValue = Node->val > maxValue ? Node->val : maxValue;
                if (Node->left) que.push(Node->left);
                if (Node->right) que.push(Node->right);
            }
            res.push_back(maxValue);
        }
        return res;
    }
};