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
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result){
        path.push_back(cur->val);
        if (cur -> left == NULL && cur -> right == NULL) {//遇到叶子节点
            string sPath;
            for (int i = 0; i < path.size() - 1; i++){//将path里记录的路径转为string格式
                sPath += to_string (path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]); //记录最后一个节点(叶子节点)
            result.push_back(sPath); //收集一个路径
            return;
        }

        if (cur -> left){
            traversal (cur->left, path, result);
            path.pop_back();//回溯
        }

        if (cur -> right){
            traversal (cur->right, path, result);
            path.pop_back();//回溯
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if (root == NULL) return result;
        traversal(root, path, result);
        return result;
    }
};