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
    void FindPath(TreeNode* pNode, int target, vector<int> path, int currentSum, vector<vector<int>> paths)
    {
        currentSum += root->val;
        path.push_back(root->val);
        //如果是叶结点，则检验这条路径上的结点和是否等于输入的值
        bool isLeaf = ((pNode->left == NULL) && (pNode->right == NULL));
        if (currentSum == target && isLeaf)
        {
            paths.push_back(path);
        }

        //如果不是叶结点，则遍历它的子结点
        if (pNode->left != NULL)
            FindPath(pNode->left, target, path, currentSum);
        
        if (pNode->right != NULL)
            FindPath(pNode->right, target, path, currentSum);

        //回溯
        currentSum -= pNode->val;
        path.pop_back();
    }


    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if (root == NULL) return;
        vector<int> path;
        int currentSum = 0;
        vector<vector<int>> paths;
        FindPath(root, target, path, currentSum, vector<vector<int>> paths);
    }
};