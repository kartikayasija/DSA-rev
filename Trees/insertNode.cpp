class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // if(!root) {
        //     return new TreeNode(val);
        // }

        // if(root->val > val) {
        //     root->left = insertIntoBST(root->left, val);
        // } else {
        //     root->right = insertIntoBST(root->right, val);
        // }
        f(root, val);
        return root;
    }

    void f(TreeNode* &root, int val) {
        if(!root) {
            root = new TreeNode(val);
            return;
        }

        if(root->val > val) {
            f(root->left, val);
        } else {
            f(root->right, val);
        }
        return;
    }
};