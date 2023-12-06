class Solution {
public:
    string tree2str(TreeNode* root) {
        if(!root) return "";

        string val = to_string(root->val);

        //if root->left "(2)" else "";
        string left = root->left ? "(" + tree2str(root->left) + ")" : "";
        string right = root->right ? "(" +tree2str(root->right) + ")" : "";

        //case if left is null but right is not null, we dont have to omit for this case
        if(!root->left and root->right){
            left += "()";
        } 

        return val + left + right;
    }
};