class Solution {
public:
    vector<vector<char>> result;

    //main
    void solveSudoku(vector<vector<char>>& board) {
        f(board, 0, 0);
        board = result;
    }

    //rec
    void f(vector<vector<char>>& board, int row, int col){

        //base
        if(row == board.size()){
            result = board;
            return;
        }
        

        //rec
        int nextRow, nextCol;
        if(col == board[0].size()){
            nextRow = row+1;
            nextCol = 0;
        } else {
            nextRow = row;
            nextCol = col+1;
        }
        
        if(board[row][col] != '.'){
            f(board, nextRow, nextCol);
            return;
        }

        for(char i='1'; i<='9'; i++){
            // i will be converted to int
            if(!isValid(board, row, col, i)){
                continue;
            }

            board[row][col] = i;
            f(board, nextRow, nextCol);

            board[row][col] = '.';
        }
    }

    //helpers
    bool isValid(vector<vector<char>>& board, int row, int col, int target){
        //row
        for(int i=0; i<board[0].size(); i++){
            if(board[row][i] == target){
                return false;
            }
        }

        //col
        for(int i=0; i<board.size(); i++){
            if(board[i][col] == target){
                return false;
            }
        }

        int startRow = getMatrix(row);
        int startCol = getMatrix(col);
        //in matrix
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[startRow+i][startCol+j] == target){
                    return false;
                }
            }
        }

        return true;
    }

    int getMatrix(int i){
        while(i%3!=0){
            i--;
        }

        return i;
    }
};