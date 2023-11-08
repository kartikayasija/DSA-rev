class Solution {
public:
    int totalSum;
    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        if((totalSum+target)%2 != 0) {
            return 0;
        }
        int newTarget = (totalSum + target) / 2;
        if(newTarget <0 ){
            return 0;
        }
        vector<vector<int>> memo(nums.size()+1, vector<int> (newTarget+1, -1));
        return f(nums, 0, newTarget, memo);
    }

    int f(vector<int>& nums, int idx, int target, vector<vector<int>>& memo) {

        //base
        if (idx == nums.size()) {
            if (target == 0) {
                return 1;
            }
            return 0;
        }

        //memo
        if(memo[idx][target] != -1) {
            return memo[idx][target];
        }

        //rec

        int considered = (target >= nums[idx]) ? f(nums, idx+1, target-nums[idx], memo) : 0;
        int notConsidered = f(nums, idx+1, target, memo);

        return memo[idx][target] = considered+notConsidered;
    }
};