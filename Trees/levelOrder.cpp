class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;

        //q-> root
        q.push(root);

        vector<vector<int>> result;

        while(!q.empty()) {
            vector<int> level;

            //take size out, because it will change in the loop
            int size = q.size();

            //loop is for levels, like at a time the elements in queue are elements in 1 level
            for(int i=0; i<size; i++) {

                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }

            result.push_back(level);
        }

        return result;
    }
};