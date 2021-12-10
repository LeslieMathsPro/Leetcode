class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        int depth = 0;
        for (int i = 0; i < root->children.size(); i++){
            depth = max(depth, maxDepth(root->children[i]));
        }
        return depth + 1;
    }
};