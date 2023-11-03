class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(f(cost, n-1, dp), f(cost, n-2, dp));
    }

    int f(vector<int> cost, int n, vector<int> &dp){
        //base
        if(n==0 or n==1){
            return cost[n];
        }

        if(dp[n] != -1){
            return dp[n];
        }

        //rec
        int a1 = f(cost, n-1, dp) + cost[n];
        int a2 = f(cost, n-2, dp) + cost[n];
        dp[n] = min(a1,a2);
        return dp[n];
    }
};