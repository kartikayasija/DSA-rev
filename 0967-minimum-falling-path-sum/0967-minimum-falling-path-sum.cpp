class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));

        for(int j=0; j<matrix[0].size(); j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i=1; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                int a1 = dp[i-1][j];  
                int a2 = j>0 ? dp[i-1][j-1] : INT_MAX;
                int a3 = j<matrix[0].size()-1 ? dp[i-1][j+1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min(a1, min(a2,a3));
            }
        }



        int mini = INT_MAX;
        for(int i=0; i<matrix[0].size(); i++){
            // mini = min(mini, f(matrix, 0, i, dp));
            mini = min(mini, dp[dp.size()-1][i]);
        }
        return mini;
    }



    int f(vector<vector<int>>& matrix, int row, int col, vector<vector<int>> &mem) {

        //base
        if(col<0 or col>=matrix[0].size()){
            return INT_MAX;
        }
        if(row==matrix.size()-1){
            return matrix[row][col];
        }

        //mem
        if(mem[row][col] != -1){
            return mem[row][col];
        }

        //rec
        int a1 = f(matrix, row+1, col, mem);        
        int a2 = f(matrix, row+1, col+1, mem);
        int a3 = f(matrix, row+1, col-1, mem);

        return mem[row][col] = matrix[row][col] + min(a1, min(a2,a3));
    }
};