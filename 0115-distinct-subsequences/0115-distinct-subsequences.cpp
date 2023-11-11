class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> memo (s.size(), vector<int> (t.size(), -1));
        return f(s,t,0,0,memo);
    }

    int f(string& s, string& t, int idx1, int idx2, vector<vector<int>>& memo) {

        //base
        if(idx2 == t.size()) {
            return 1;
        }

        if(idx1 == s.size()) {
            return 0;
        }

        //memo
        if(memo[idx1][idx2] != -1) {
            return memo[idx1][idx2];
        }


        //rec
        if(s[idx1] == t[idx2]) {
            memo[idx1][idx2] = f(s, t, idx1+1, idx2+1, memo) + f(s, t, idx1+1, idx2, memo);
        } else {
            memo[idx1][idx2] = f(s, t, idx1+1, idx2, memo);
        }

        return memo[idx1][idx2];
    }
};