class Solution {
public:
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return f(inorder, postorder, 0, inorder.size() - 1);
    }

    TreeNode* f(vector<int>& inorder, vector<int>& postorder, int l, int r) {
        if (l > r) {
            return NULL;
        }

        int val = postorder.back();
        postorder.pop_back();

        TreeNode* newRoot = new TreeNode(val);
        int idx = mp[val];

        //build right first
        newRoot->right = f(inorder, postorder, idx + 1, r);
        newRoot->left = f(inorder, postorder, l, idx - 1);

        return newRoot;
    }
};