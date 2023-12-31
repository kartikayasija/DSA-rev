class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> memo (prices.size(), vector<vector<int>> (2, vector<int>(3, -1)));
        int maxTransaction = 2;
        return f(prices, 0, 1, memo, maxTransaction);
    }
    int f(vector<int>&nums, int idx, int buy, vector<vector<vector<int>>>&memo, int maxTransaction) {
        //base
        if(idx == nums.size() or maxTransaction == 0) {
            return 0;
        }

        //memo
        if(memo[idx][buy][maxTransaction] != -1) {
            return memo[idx][buy][maxTransaction];
        }

        //rec
        if(buy == 1) {
            return memo[idx][buy][maxTransaction] = max(-nums[idx]+f(nums, idx+1, 0, memo, maxTransaction), f(nums, idx+1, 1, memo, maxTransaction));
        }

        else {
            
            return memo[idx][buy][maxTransaction] = max(nums[idx]+f(nums, idx+1, 1, memo, maxTransaction-1), f(nums, idx+1, 0, memo, maxTransaction));
        }
    }
};