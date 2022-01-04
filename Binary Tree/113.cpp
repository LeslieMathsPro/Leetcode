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
private:
    vector<int> path;
    vector<vector<int>> result;
    //递归函数不需要返回值，因为我们需要遍历整个树
    void traversal(TreeNode* cur, int count){
        if (!cur->left && !cur->right && count == 0){
            result.push_back(path);
            return;
        }

        if (!cur->left && !cur->right) return;

        if (cur->left) {//左， 空节点不遍历
            path.push_back(cur->left->val);
            count -= cur->left->val;
            traversal(cur->left, count); //递归
            count += cur->left->val;     //回溯
            path.pop_back();             //回溯
        } 

        if (cur->right) {
            path.push_back(cur->right->val);
            cout -= cur->right->val;
            traversal(cur->right, count);
            count += cur->right->val;
            path.pop_back();
        }

        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        result.clear();
        path.clear();
        if (root == nullptr) return result;
        path.push_back(root->val);
        traversal(root, targetSum - root->val);
        return result;
    }
};