class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return f(cost, n, dp);
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
        int a1 = f(cost, n-1, dp) + (n < cost.size() ? cost[n] : 0);
        int a2 = f(cost, n-2, dp) + (n < cost.size() ? cost[n] : 0);

        dp[n] = min(a1,a2); 
        return dp[n];
    }
};