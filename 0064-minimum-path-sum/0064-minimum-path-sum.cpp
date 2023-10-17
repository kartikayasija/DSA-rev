class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(), 0));


        for(int i=dp.size()-1; i>=0; i--){
            for(int j = dp[0].size() - 1; j>=0; j--){

                if(i==dp.size()-1 and j==dp[0].size()-1){
                    dp[i][j] = grid[i][j];
                }

                //last row
                else if(i==dp.size()-1){  
                    dp[i][j] = dp[i][j+1] + grid[i][j];
                } 
                
                //rightest col
                else if(j==dp[0].size()-1){
                    dp[i][j] = dp[i+1][j] + grid[i][j];
                }

                // else everyone will have 2 choices
                else{
                    dp[i][j] = min(dp[i][j+1], dp[i+1][j]) + grid[i][j];
                }
            }
        }

        return dp[0][0];
    }
};