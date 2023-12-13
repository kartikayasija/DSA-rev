class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        f(root);
        return root;
    }
    int sum = 0;
    void f(TreeNode* root) {
        if(!root) return;

        f(root->right);
        sum = sum + root->val;
        root->val = sum;
        f(root->left);
    }
};