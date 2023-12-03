/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if(root->val < key) {
            root->right = deleteNode(root->right, key);

        } else {
            //case when both child are present
            if(root->left and root->right) {

                //find max of left subtree or min of right subtree
                int maxi = max(root->left);

                //make maxi root,
                root->val = maxi;

                //remove maxi from tree below
                root->left = deleteNode(root->left, maxi);
            }

            else if(root->left) {
                return root->left;
            }

            else{
                return root->right;
            }
        }

        return root;
    }

    int max(TreeNode* root) {
        if(!root->right) return root->val;
        return max(root->right);
    }
};