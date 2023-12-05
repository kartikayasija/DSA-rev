class Solution {
public:
    int mini = INT_MAX;
    int minDiffInBST(TreeNode* root) {
        f(root);

        return mini;
    }
    int prev = -1;
    void f (TreeNode* root) {
        if(!root) return;

        f(root->left);

        // if its -1, means its start case, so dont take min
        if(prev != -1) mini = min(mini, abs(root->val - prev));

        //update prev value
        prev = root->val;
        
        f(root->right);
    }
};