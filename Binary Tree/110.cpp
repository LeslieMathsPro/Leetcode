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
//二叉树的深度: 指从根节点到该节点的最长简单路径边的条数
//二叉树的高度: 指从该节点到叶子节点的最长简单路径边的条数
//因为求深度可以从上到下去查，所以需要前序遍历(中左右)
//而高度只能从下到上去查，所以只能后序遍历(左右中)
class Solution {
public:
    //1. 明确递归函数的参数与返回值
    //-1 表示已经不再是平衡二叉树了，否则返回值是以该节点为根节点的树的高度
    int getHeight(TreeNode* node){
        //2. 明确终止条件
        if (node == nullptr){
            return 0;
        }
        //3. 明确单层递归的逻辑
        int leftHeight = getHeight(node->left);//左
        if (leftHeight == -1) return -1;
        int rightHeight = getHeight(node->right);//右
        if (rightHeight == -1) return -1;

        int result;
        if (abs(leftHeight-rightHeight) > 1) { //中
            result = -1;
        } else {
            result = 1 + max(leftHeight, rightHeight);
        }

        return result;
    }
    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1 ? false : true;
    }
};