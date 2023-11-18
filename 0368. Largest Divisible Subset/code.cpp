class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<vector<vector<int>>> memo (nums.size()+1, vector<vector<int>>(nums.size()+1, vector<int>(0)));
        sort(nums.begin(), nums.end());
        return f(nums, 0, -1, memo);
    }

    vector<int> f(vector<int>& nums, int idx, int prevIdx, vector<vector<vector<int>>>&memo) 
    {
        //base
        if(idx == nums.size()) {
            return {};
        }

        // memo
        if(memo[idx][prevIdx+1].size() != 0) {
            return memo[idx][prevIdx+1];
        }

        //rec
        vector<int> notTake = f(nums, idx+1, prevIdx, memo);

        bool condition = prevIdx==-1 or nums[idx] % nums[prevIdx] == 0;
        vector<int> take = {};
        if(condition) {
            take = f(nums, idx+1, idx, memo);
            take.push_back(nums[idx]);
        }

        return memo[idx][prevIdx+1] = take.size() > notTake.size() ? take : notTake;
    }
};