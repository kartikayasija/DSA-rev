class Solution {
public:
    int count = 0;
    int goodNodes(TreeNode* root) {
        f(root, INT_MIN);

        return count;
    }

    void f(TreeNode* root, int maxSoFar) {
        if(!root) {
            return;
        }

        //inc count if its greater equal of maxSofar of current path
        if(root->val >= maxSoFar) {    
            count++;
        }


        //run for left, right, send maxSoFar as the maximum of root->val and prev MAximum
        f(root->left, max(root->val, maxSoFar));
        f(root->right, max(root->val, maxSoFar));


        return;
    }
        
};