class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        f(candidates, temp, target, 0);
        return result;
    }

    void f(vector<int>& candidates, vector<int>& temp, int target, int idx){
        //base
        if(target==0){
            result.push_back(temp);
            return;
        }

        //rec
        for(int i=idx; i<candidates.size(); i++){
            if(target<candidates[i]){
                continue;
            }

            temp.push_back(candidates[i]);

            f(candidates, temp, target - candidates[i], i);
            /*
                idx ko i isly bheja kykuki
                [2,3,5] ->
                [2] -> 2,3,5   --- i was 0 and had to continue from 0 only
                [3] -> X,3,5       i was 1 and had to continue from 1 idx only
                [5] -. X,X,5       i was 2 and had to continue from 2 idx only ,
            */
            //backtrack
            temp.pop_back();
        }
    }

};