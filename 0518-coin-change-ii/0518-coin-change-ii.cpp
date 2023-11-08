class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size()+1, vector<int> (amount+1, -1));
        return f(coins, amount, 0, memo);
    }

    int f(vector<int>& coins, int amount, int idx, vector<vector<int>>& memo) {
        //base
        if(amount == 0) {
            return 1;
        }
        if(idx == coins.size()){
            return 0;
        }

        //memo
        if(memo[idx][amount] != -1) {
            return memo[idx][amount];
        }

        //rec
        int considered = (amount>=coins[idx]) ? f(coins, amount - coins[idx], idx, memo) : 0;
        int notConsidered = f(coins, amount, idx+1, memo);

        return memo[idx][amount] = considered + notConsidered;
    }
};

/*
    https://youtu.be/l_nR5X9VmaI?feature=shared
*/