class Solution {
public:
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
        f(root, 0);
        return ans;
    }

    void f(TreeNode* root, int level) {
        if(!root) return;

        //there will only one node at each level
        if(level == ans.size()){
            ans.push_back(root->val);
        }

        //give priorty to the most rightest node
        f(root->right, level+1);
        f(root->left, level+1);
    }
};