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
    bool DoesTree1HaveTree2(TreeNode* A, TreeNode* B) {
        if (B == NULL)
            return true;
        
        if (A == NULL)
            return false;

        if (A->val != B->val)
            return false;

        return DoesTree1HaveTree2(A->left, B->left) && DoesTree1HaveTree2(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        bool result = false;

        if (A != NULL && B!= NULL)
        {
            if (A->val == B->val)
                result = DoesTree1HaveTree2(A, B);
            if (!result)
                result = isSubStructure(A->left, B);
            if (!result)
                result = isSubStructure(A->right, B);
        }

        return result;
    }
};