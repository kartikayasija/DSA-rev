class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        // to handle the example 2
        if(digits.size()==0){
            return {};
        }
        return f(digits,0,map);
    }

    vector<string> f(string &digits, int idx,vector<string> &map){

        //base
        if(idx==digits.size()){
            return {""};
        }

        //rec
        vector<string> rec_ans = f(digits,idx+1,map);
        string unit_string=map[digits[idx]-'0'];
        vector<string> my_ans;
        for(auto x: rec_ans){
            for(auto s: unit_string){
                string resultant = s+x;
                my_ans.push_back(resultant);
            }
        }      
        return my_ans;
    }
};