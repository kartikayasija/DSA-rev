class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {

        if(!root) return NULL;

        //handle root

        //run only for right in this case
        if(root->val < low) {
            root = trimBST(root->right, low, high);
        }

        //run only for left in this case
        else if(root->val > high) {
            root = trimBST(root->left, low, high);
        }

        //run for both, root is alright, run for left,right children
        else{
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }

        return root;
    }
};