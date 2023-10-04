class Solution {
public:
    int ways = 0;
    int totalNQueens(int n) {
        vector<vector<bool>> chess(n, vector<bool>(n, false));
        f(n, 0, chess);
        return ways;
    }

    void f(int n, int idx, vector<vector<bool>> &chess){
        
        if(idx==n){
            ways++;
            return;
        }

        //rec
        for(int i=0; i<n; i++){
            if(!isSafe(idx, i, chess)){
                continue;
            }

            chess[idx][i] = true;
            f(n, idx+1, chess);

            //backtrack
            chess[idx][i] = false;
        }

    }
    bool isSafe(int row, int col, vector<vector<bool>> &chess){

        //verticle
        for(int i=0; i<row; i++){
            if(chess[i][col]){
                return false;
            }
        }

        //left diag
        int i = row;
        int j = col;

        while(i>=0 and j>=0){
            if(chess[i--][j--]){
                return false;
            }
        } 

        //right diag
        i = row;
        j = col;
        while(i>=0 and j<chess.size()){
            if(chess[i--][j++]){
                return false;
            }
        }

        return true;
    }
};