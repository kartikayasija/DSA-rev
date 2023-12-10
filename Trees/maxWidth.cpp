class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int maxi = 0;
        while(!q.empty()) {
            int size = q.size();

            //left and right idx
            //left will automatically get updated when a new level start
            long long left = q.front().second;
            long long right = q.back().second;
            
            for(int i=0; i<size; i++) {
                auto nodePair = q.front();
                long long idx = nodePair.second - left;
                q.pop();

                //add left and right child with their index
                if(nodePair.first->left) {
                    q.push({ nodePair.first->left, 2*idx + 1 });
                }
                if(nodePair.first->right) {
                    q.push({ nodePair.first->right, 2*idx + 2 });
                }
            }

            //update max
            maxi = max(maxi, int(right - left + 1));
        }

        return maxi;
    }
};