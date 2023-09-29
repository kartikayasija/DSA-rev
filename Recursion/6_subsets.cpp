class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return f(nums,0);
    }

    vector<vector<int>> f(vector<int>& nums,int idx){
        
        if(idx==nums.size()){
            return {{}};
        }
        
        // recursive
        vector<vector<int>> rec_ans = f(nums,idx+1);
        int first_element = nums[idx];
        vector <vector<int>> result;
        for(auto x: rec_ans){
            result.push_back(x);
            x.insert(x.begin(),first_element);
            result.push_back(x);
        } 

        return result;
    }
};

/*
https://leetcode.com/problems/subsets/description/

[1,2,3]
expectation -> [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
faith -> [2,3] -> [[],[2],[2,3],[3]] 

ek baar 1 push_front krdo
ek baar mat kro

*/