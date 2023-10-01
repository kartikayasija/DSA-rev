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


        string unit_string= map[digits[idx] - '0'];
        vector<string> my_ans;

        for(auto x: rec_ans){  
            for(auto s: unit_string){ //abc
                my_ans.push_back(s+x);
            }
        }      
        return my_ans;
    }
};

/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

Expectation ->
"234" -> ["adg","bdg","cdg","aeg","beg","ceg","afg","bfg","cfg","adh","bdh","cdh","aeh","beh","ceh","afh","bfh","cfh","adi","bdi","cdi","aei","bei","cei","afi","bfi","cfi"]

2   3   4

a   d   g
b   e   h
c   f   i

faith ->
"34" -> [ye recursion nikalega]

our work ->
"234" -> "2" left ('abc') 
recursion ke har ans ke age 'a' then 'b' then 'c'

"2" -> 2 -> map[2] -> "abc"
 
*/