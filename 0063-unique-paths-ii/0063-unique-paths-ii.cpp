class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        vector<vector<int>> mem(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        return f(obstacleGrid, 0, 0, mem);
    }

    int f(vector<vector<int>>& obstacleGrid, int n, int m, vector<vector<int>> &mem){

        if(n>=obstacleGrid.size() or m>=obstacleGrid[0].size() or obstacleGrid[n][m]==1){
            return 0;
        }

        if(n==obstacleGrid.size()-1 and m==obstacleGrid[0].size()-1){
            return 1;
        }

        if(mem[n][m]==-1){
            mem[n][m] = f(obstacleGrid, n+1, m, mem) + f(obstacleGrid, n, m+1, mem);
        }

        return mem[n][m];
    }
};

/*

https://leetcode.com/problems/unique-paths-ii

|_|____________|

one box has two options to move,
 to simply un dono options ko plus krdia
 //bootom
 //right

f(n,m) = f(n+1, m) + f(n, m+1)


*/