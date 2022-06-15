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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr)return ans;
        TreeNode* tn=root;
        queue<TreeNode*> layer;
        layer.push(tn);
        while(!layer.empty()){
            vector<int> this_layer;
            //获取当前层级的队列长度
            int qsize=layer.size(); 
            //循环遍历当前层级的所有节点
            for(int tmp=0;tmp<qsize;tmp++){
                tn=layer.front();
                layer.pop();
                this_layer.push_back(tn->val);
                //将下一层级的所有节点从左往右添加至队列尾
                if(tn->left)layer.push(tn->left);
                if(tn->right)layer.push(tn->right);
            }
            ans.push_back(this_layer);
        }
        return ans;
    }
};