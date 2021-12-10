struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//递归法
//二叉树的前序遍历
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
    void traversal(TreeNode *cur, vector<int>& vec){
        if (cur == NULL) return;
        vec.push_back(cur->val); // 中
        traversal(cur->left, vec); // 左
        traversal(cur->right, vec); // 右
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

//中序排序
class Solution {
public:
    void traversal(TreeNode *cur, vector<int>& vec){
        if (cur == NULL) return;
        traversal(cur->left, vec);
        vec.push_back(cur->val);
        traversal(cur->right, vec);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

//后序排序
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
    void traversal(TreeNode *cur, vector<int>& vec){
        if (cur == NULL) return;
        traversal(cur->left, vec);
        traversal(cur->right, vec);
        vec.push_back(cur->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};


//迭代法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;//这里的TreeNode为什么要加*？
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()){
            TreeNode *node = st.top(); //中
            st.pop();
            result.push_back(node->val);
            if (node->right) st.push(node->right); //右 (空节点不入栈)
            if (node->left) st.push(node->left); //左 (空节点不入栈)
        }
        return result;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()){
            TreeNode *node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

//二叉树的中序遍历
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) {
                //指针来访问节点，访问到最底层
                st.push(cur); //将访问的节点放进栈
                cur = cur -> left;  //左
            }else{
                cur = st.top(); // 从栈里弹出的数据，就是要处理的数据(放进result里的数据)
                st.pop();
                result.push_back(cur->val); //中
                cur = cur->right;   //右
            }
        }
        return result;
    }
};