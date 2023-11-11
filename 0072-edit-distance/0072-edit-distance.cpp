class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo (word1.size(), vector<int> (word2.size(), -1));
        return f(word1, word2, 0, 0, memo);
    }

    int f(string& s1, string& s2, int i1, int i2, vector<vector<int>>& memo) {

        //base
        if(i1 == s1.size()) {
            return s2.size() - i2;
        }

        if(i2 == s2.size()) {
            return s1.size() - i1;
        }

        //memo
        if(memo[i1][i2] != -1) {
            return memo[i1][i2];
        }

        //rec
        if(s1[i1] == s2[i2]) {
            memo[i1][i2] = f(s1, s2, i1+1, i2+1, memo);
        } else {
            memo[i1][i2] = 1 + min(f(s1, s2, i1+1, i2+1, memo), min( f(s1, s2, i1, i2+1, memo), f(s1, s2, i1+1, i2, memo) ));
        }

        return memo[i1][i2];
    }
};

/*
    https://youtu.be/XYi2-LPrwm4?feature=shared

    1 +
    insert -> f(i1, i2+1)
    delete -> f(i1+1, i2)
    replace -> f(i1+1, i2+1)
*/