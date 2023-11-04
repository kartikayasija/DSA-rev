class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> memo(grid.size(), vector<int> (grid[0].size(), -1));
        return f(grid, 0, 0, memo);
    }

    int f(vector<vector<int>>& grid, int row, int col, vector<vector<int>> &memo) {

        //base
        if(row == grid.size() or col == grid[0].size()){
            return INT_MAX;
        }
        if(row == grid.size()-1 and col == grid[0].size()-1){
            return grid[row][col];
        }

        //memo
        if(memo[row][col] != -1){
            return memo[row][col];
        }
        //rec
        int sum1 = f(grid, row+1, col, memo);
        int sum2 = f(grid, row, col+1, memo);
        
        return memo[row][col] = min(sum1, sum2) + grid[row][col];
    }
};