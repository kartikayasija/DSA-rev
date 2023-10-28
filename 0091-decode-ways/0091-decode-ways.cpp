class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') {
            return 0;
        }
        vector<int> dp(s.size(), 0);
        dp[0] = 1;
        for(int i=1; i<dp.size(); i++){
            if(s[i-1]=='0' and s[i]=='0'){
                dp[i]=0;
            }
            else if(s[i-1]=='0' and s[i]!='0'){
                dp[i] = (i>=2) ? dp[i-1] : 0;
            }
            else if(s[i-1]!='0' and s[i]=='0'){
                int n = makeTodigit(s[i-1], s[i]);
                if(n<=26){
                    dp[i] = (i>=2) ? dp[i-2] : 1;
                }
            }
            else if(s[i-1]!='0' and s[i]!='0'){
                dp[i]=dp[i-1];
                int n = makeTodigit(s[i-1], s[i]);
                if(n<=26){
                    dp[i] += (i>=2) ? dp[i-2] : 1;
                }
            }
        }

        return dp[s.size()-1];
    }

    int makeTodigit(char a, char b){
        string s ="";
        s = s+a+b;
        return stoi(s);
    }
};