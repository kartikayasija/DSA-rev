class Solution {
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        f(root);

        return ans;
    }

    void f(TreeNode* root) {
        if(!root) return;

        ans.push_back(root->val);
        f(root->left);
        f(root->right);

        return;
    }
};