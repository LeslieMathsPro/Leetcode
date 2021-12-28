struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}//这个是构造函数
};

//递归法
//1.确定递归函数的参数与返回值: 确定哪些参数是递归的过程中需要处理的，那么就在递归函数里加上这个参数，
//并且还要明确每次递归的返回值是什么进而确定递归函数的返回类型
//2.确定终止条件: 写完了递归函数，运行的时候经常遇到栈溢出的错误，就是没写终止条件或者终止条件写得不对
//操作系统也是用一个栈的结构来保存每一层递归的信息，如果递归没有终止，则操作系统的内存栈必然会溢出
//3.确定单层递归的逻辑：确定每一层递归需要处理的信息，在这里也会重复调用自己来实现递归的过程。
//
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

//递归的实现就是：每一次递归调用都会把函数的局部变量，参数值和返回地址等压入调用栈中。
//然后递归返回的时候，从栈顶弹出上一次递归的各项参数。这就是递归可以返回上一层位置的原因。
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