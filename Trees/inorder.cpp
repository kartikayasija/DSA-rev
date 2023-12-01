class Solution {
public:
    vector<int> ans;

    vector<int> inorderTraversal(TreeNode* root) {
        f(root);
        return ans;
    }

    void f(TreeNode* root) {
        if(!root) return;

        f(root->left);
        ans.push_back(root->val);
        f(root->right);

        return;
    }
};