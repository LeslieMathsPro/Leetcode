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
    bool traversal(TreeNode* cur, int count){
        //不要去累加求和然后判断是否等于目标和，那样比较麻烦，可以用递减，
        //让计数器count初始化为目标和，然后每次减去遍历路径节点上的数值。
        if(!cur->left && !cur->right && count == 0) return true;
        if(!cur->left && !cur->right ) return false; //遇到叶子节点直接返回

        if (cur->left){// 左
            count -= cur->left->val; // 递归，处理节点；
            if (traversal(cur->left, count)) return true;
            count += cur->left->val; // 回溯，撤销处理结果
        }

        if (cur->right){//右
            count -= cur->right->val; //递归，处理节点；
            if (traversal(cur->right, count)) return true;
            count += cur->right->val; //回溯，撤销处理结果
        }

        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return traversal(root, sum - root -> val);
    }
};