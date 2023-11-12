class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> memo (s.size()+1, vector<int> (p.size()+1, -1));
        return f(s, p, 0, 0, memo);
    }

    bool f(string& s, string& p, int i1, int i2, vector<vector<int>>& memo) {

        //base
        if(i1==s.size() and i2==p.size()){
            return true;
        }
        if(i2 == p.size()) {
            return false;
        }
        if(i1 == s.size()) {
            for(int i=i2; i<p.size(); i++) {
                if(p[i] != '*'){
                    return false;
                }
            }
            return true;
        }

        //memo
        if(memo[i1][i2] != -1) {
            return memo[i1][i2];
        }

        //rec
        if(s[i1] == p[i2] or p[i2] == '?') {
            memo[i1][i2] = f(s, p, i1+1, i2+1, memo);
        }  
        else if (p[i2] == '*'){   //star case
            memo[i1][i2] = f(s, p, i1, i2+1, memo) or f(s, p, i1+1, i2, memo);
        }
        else {
            memo[i1][i2] = false;
        }

        return memo[i1][i2];
    }
};