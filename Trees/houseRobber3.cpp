class Solution {
public:

    // dont create another bool canTake (difficult in memo)
    // use simple logic, if at one level it is considering node, 
    // then dont allow it for next level 

    unordered_map<TreeNode*, int> memo; 
    int rob(TreeNode* root) {
        return f(root);
    }

    int f(TreeNode* root) {
        
        //base
        if(!root) return 0;
        
        //memo
        if(memo.find(root) != memo.end()) {
            return memo[root];
        }

        //take case, skip one level
        int take = root->val;
        if(root->left) take += f(root->left->left) + f(root->left->right);
        if(root->right) take += f(root->right->left) + f(root->right->right);

        //dont take case, run for next level
        int notTake = f(root->left) + f(root->right);

        return memo[root] = max(take, notTake);
    }
};