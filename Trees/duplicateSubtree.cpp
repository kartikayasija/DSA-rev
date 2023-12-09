class Solution {
public:
    vector<TreeNode*> result;
    unordered_map<string, int> mp;


    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string s = f(root);
        return result;
    }


    //make pre/post/in of tree in string, and match for all nodes
    //use map for matching, if traversal is same or not
    string f ( TreeNode* root ) {

        if(!root) return "null";
        string left = f(root->left);
        string right = f(root->right);

        string s = to_string(root->val) + "," + left + "," + right;

        if(mp[s] == 1) {
            result.push_back(root);
        }

        mp[s]++;

        return s;
    }
};