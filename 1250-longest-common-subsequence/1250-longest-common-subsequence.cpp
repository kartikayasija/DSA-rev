class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo (text1.size(), vector<int>(text2.size(), -1));
        return f(text1, 0, text2, 0, memo);
    }

    int f(string& str1, int idx1, string& str2, int idx2, vector<vector<int>>& memo) {

        //base
        if(idx1 == str1.size() or idx2 == str2.size()) {
            return 0;
        }

        //memo
        if(memo[idx1][idx2] != -1) {
            return memo[idx1][idx2];
        }

        //rec
        if(str1[idx1] == str2[idx2]) {
            return memo[idx1][idx2] = 1 + f(str1, idx1+1, str2, idx2+1, memo);
        }
            
        return memo[idx1][idx2] = max(f(str1, idx1+1, str2, idx2, memo), f(str1, idx1, str2, idx2+1, memo));
        
    }
};