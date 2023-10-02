class Solution {
public:
    vector<vector<string>> result;
    vector<vector<string>> solveNQueens(int n) {
        string str;
        for(int i=0; i<n; i++){
            str+=".";
        }

        vector<string> chess(n, str);

        f(chess, 0);

        return result;
    }

    void f(vector<string> &chess, int row){
        //base
        if(row==chess.size()){
            result.push_back(chess);
            return;
        }

        //rec
        for(int i=0; i<chess.size(); i++){  //har ek ke liye n options
            if(!isSafe(chess, row, i)){
                continue;
            }
            chess[row][i] = 'Q';
            f(chess, row+1);
            chess[row][i] = '.';
        }
    }

    bool isSafe(vector<string> &chess, int row, int col){

        //verticle
        for(int i=0; i<row; i++){
            if(chess[i][col]=='Q'){
                return false;
            }
        }

        //left diagonal
        int i=row;
        int j=col; 
        while(i>=0 and j>=0){
            if(chess[i--][j--]=='Q'){
                return false;
            }
        }

        //right diagonal
        i=row;
        j=col;
        while(i>=0 and j<chess.size()){
            if(chess[i--][j++]=='Q'){
                return false;
            }
        }

        return true;
    }
};

/*
    https://leetcode.com/problems/n-queens

    pehle sb jgh place kro
    fr queen ki safety check kro

    https://youtu.be/05y82cP3bJo?feature=shared

*/