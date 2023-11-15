class Solution {
public:
    int maxProfit(vector<int>&nums) {
        vector<vector<int>> memo (nums.size(), vector<int> (2, -1));
        return f(nums, 0, 1, memo);
    }

    int f(vector<int>&nums, int idx, int buy, vector<vector<int>>&memo) {
        //base
        if(idx == nums.size()) {
            return 0;
        }

        //memo
        if(memo[idx][buy] != -1) {
            return memo[idx][buy];
        }

        //rec

        //means we can buy
        if(buy == 1) {
            /*
                either we can buy on that day, or move further
                if we buy, then subtract that money, and toggle the buy button to OFF
                else just skip to next day
                take max of both these cases
            */
            return memo[idx][buy] = max(-nums[idx]+f(nums, idx+1, 0, memo), f(nums, idx+1, 1, memo));
        }

        //means we have to sell (buy switch is off)
        else {
            /*
                same applies here, we have two switch, either sell, or not sell
                if we sell, then plus that amount and toggle the buy button to ON
                else just move to next case
            */
            return memo[idx][buy] = max(nums[idx]+f(nums, idx+1, 1, memo), f(nums, idx+1, 0, memo));
        }
    }
};