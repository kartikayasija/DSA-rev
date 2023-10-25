class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> memo(coins.size(),vector<int>(amount+1, -1));
        int ans = f(coins, amount, 0, memo);
        return ans==INT_MAX-1 ? -1 : ans;
    }

    int f(vector<int>& coins, int amt, int idx, vector<vector<int>> &memo){
        //base
        if(idx==coins.size()){
            if(amt==0){
                return 0;
            }
            return INT_MAX-1;
        }

        if(memo[idx][amt] != -1){
            return memo[idx][amt];
        }

        //rec  
        //if not considered then, previous ans is continued
        if(coins[idx]>amt){
            int ans = f(coins, amt, idx+1, memo);
            memo[idx][amt] = ans;
            return ans;
        }

        int rec_ans_considered = 1 + f(coins, amt-coins[idx], idx, memo);
        int rec_ans_notConsidered = f(coins, amt, idx+1, memo);
        int ans = min(rec_ans_considered, rec_ans_notConsidered);
        memo[idx][amt] = ans;
        return ans;
    }
};