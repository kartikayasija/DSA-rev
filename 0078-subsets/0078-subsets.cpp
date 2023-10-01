class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> result;
        f(nums,0, result, v);

        return result;
    }

    void f(vector<int> &nums, int idx, vector<vector<int>> &result, vector<int> &v){

        //base
        if(idx==nums.size()){
            result.push_back(v);
            return;
        }

        // recursive

        v.push_back({nums[idx]});
        f(nums, idx+1, result, v);
        v.pop_back();
        f(nums, idx+1, result, v);
    }
};