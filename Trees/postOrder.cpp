class Solution {
public:
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        f(root);
        return ans;
    };

    void f(TreeNode* root) {
        if(!root) return;

        f(root->left);
        f(root->right);
        ans.push_back(root->val);

        return;
    };

};