class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;

        int levelNumber = -1;

        //q-> root
        q.push(root);

        vector<vector<int>> result;

        while(!q.empty()) {
            vector<int> level;

            //take size out, because it will change in the loop
            int size = q.size();
            levelNumber++;
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

            //just reverse at odd level
            if(levelNumber % 2 == 1){
                reverse(level.begin(), level.end());
            } 
            result.push_back(level);
        }

        return result;
    }
};