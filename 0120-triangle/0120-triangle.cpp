class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> mem(triangle.size(), vector<int>(triangle[triangle.size() - 1].size(), -1));

        return f(triangle, 0, 0, mem);
    }

    int f(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& mem) {

        //base
        if(row == triangle.size()-1){
            return triangle[row][col];
        }

        //mem
        if(mem[row][col] != -1){
            return mem[row][col];
        }
        
        //rec
        int a1 = f(triangle, row+1, col, mem);
        int a2 = f(triangle, row+1, col+1, mem);

        return mem[row][col] = min(a1, a2) + triangle[row][col];
    }
};