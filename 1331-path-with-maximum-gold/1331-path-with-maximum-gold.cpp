class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        int maxi = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 0){
                    continue;
                }
                maxi = max(maxi, f(grid, i, j, visited));
            }
        }
        return maxi;
    }

    int f(vector<vector<int>>& grid, int row, int col, vector<vector<bool>> &visited){

        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || visited[row][col] || grid[row][col] == 0) {
        return 0;
    }

        visited[row][col] = true;

        //rec
        int left = grid[row][col] + f(grid, row, col-1, visited);
        int right = grid[row][col] + f(grid, row, col+1, visited);
        int top = grid[row][col] + f(grid, row-1, col, visited);
        int bottom = grid[row][col] + f(grid, row+1, col, visited);

        visited[row][col] = false;

        return max(top, max(bottom, max(left, right)));

    }
};