class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        return f(grid, 0, 0, 0);
    }

    bool f(vector<vector<int>>& grid, int row, int col, int move){

        //base
        /* 
            grid[row][col] != move
            to check if our move is following the path of input grid
            if not then return false
        */
        if(row<0 or col<0 or row>=grid.size() or col>=grid.size() or grid[row][col] != move){
            return false;
        }
        int last_move = grid.size()*grid.size() - 1;
        if(move==last_move){
            return true;
        }

        //rec
        return f(grid, row-2, col+1, move+1) or
        f(grid, row-1, col+2, move+1) or
        f(grid, row+1, col+2, move+1) or
        f(grid, row+2, col+1, move+1) or
        f(grid, row+2, col-1, move+1) or
        f(grid, row+1, col-2, move+1) or
        f(grid, row-1, col-2, move+1) or 
        f(grid, row-2, col-1, move+1);

    }
};