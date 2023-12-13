class Solution {
public:
    int maximum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        f(root);
        return maximum;
    }
    

    //function finds the maximum subpath in left and right
    //like for ex1 , it will return max(1-2, 1-3)
    //it will also update our globalMaximum (1-2-3)
    int f(TreeNode* root) {
        if(!root) return 0;

        int left = max(f(root->left), 0);
        int right = max(f(root->right), 0);

        //update maximum
        maximum = max(root->val + left + right, maximum);

        return root->val + max(left, right);
    }
};