class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mem(n, vector<int>(m, -1));
        return f(m-1, n-1, mem);  //m and n are counted from 1,1 //but we are putting base case as 0,0 
    }

    int f(int m, int n, vector<vector<int>> &mem){

        //base
        if(n==0 or m==0){
            return 1;
        }

        //rec
        if(mem[n][m]==-1){
            mem[n][m] = f(m-1, n, mem) + f(m, n-1, mem);
        }

        return mem[n][m];
    }
};

/*
https://leetcode.com/problems/unique-paths/

expectation ->
m=3, n=3 --> ans = 6

3,3 pe jane ke 2 ways
(3,2) OR (2,3)

faith -> recursion will calculate all the ways to (3,2) and (2,3)

f(m,n) = f(m-1, n) + f(m, n-1)

*/