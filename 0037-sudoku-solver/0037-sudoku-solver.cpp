class Solution {
public:
vector<vector<char>>result;
    void solveSudoku(vector<vector<char>>& board) {
        f(board, 0, 0);
        board = result;
    }

    void f(vector<vector<char>> &board, int row, int col){

        //base
        if(row==board.size()){
            result = board;
            return;
        }

        
        // reinitialise col, if it is at end and increase row
        int nextRow, nextCol;

        if(col == board[0].size()-1){
            nextRow = row+1;
            nextCol = 0;
        } else{
            nextRow = row;
            nextCol = col+1;
        }
        

        //rec
        if(board[row][col]!='.'){
            f(board, nextRow, nextCol);
        } else{
            for(char i='1'; i<='9'; i++){
                if(!isValid(board, row, col, i)){
                    continue;
                }

                board[row][col] = i;

                f(board, nextRow, nextCol);

                //backtrack
                board[row][col] = '.';
            }
        }
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char number){

        //row
        for(int i=0; i<board[0].size(); i++){
            if(board[row][i]==number){
                return false;
            }
        }

        //col
        for(int i=0; i<board.size(); i++){
            if(board[i][col]==number){
                return false;
            }
        }

        //in matrix
        int matrixRowStart = matrixD(row);
        int matrixColStart = matrixD(col);

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[matrixRowStart+i][matrixColStart+j] == number){
                    return false;
                }
            }
        }
        

        return true;
    }


    /*
        returns starting row/col of the number
        from which the number belongs
    */

    int matrixD(int number){
        while(number%3!=0){
            number--;
        }
        return number;
    }
};