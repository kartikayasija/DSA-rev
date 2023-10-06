class Solution {
public:
    int ways = 0;
    int totalNQueens(int n) {
        vector<bool> temp2(n, false);
        vector<vector <bool>> temp(n, temp2);

        f(n, 0, temp);
        return ways;
    }

    void f(int n, int idx, vector<vector <bool>> &temp){

        //base
        if(idx == n){
            ways++;
            return;
        }


        //rec
        for(int col=0; col<n; col++){

            if(isSafe(temp, idx, col)){
                
                temp[idx][col] = true;

                f(n, idx+1, temp);

                //backtrack
                temp[idx][col] = false;

            }

        }

    }

    bool isSafe(vector<vector <bool>> &temp, int row, int col){
        //verticle
        for(int i=row; i>=0; i--){
            if(temp[i][col]){
                return false;
            }
        }

        //left diag
        int i = row;
        int j = col;
        while(i>=0 and j>=0){
            if(temp[i--][j--]){
                return false;
            }
        }

        //right diag
        i = row;
        j = col;
        while(i>=0 and j<temp.size()){
            if(temp[i--][j++]){
                return false;
            }
        }

        return true;
    }
};