class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        f(candidates, {}, target, 0);

        return result;
    }

    void f(vector<int>& candidates, vector<int> temp, int target, int idx){
        //base
        if(target==0){
            result.push_back(temp);
            return;
        }

        //rec
        for(int i=idx; i<candidates.size(); i++){
            // when i>idx, means it is not the firs6 run of loop
            // i is incremented
            if(i>idx and candidates[i] == candidates[i-1]){
                continue;
            }
            if(target<candidates[i]){
                continue;
            }

            temp.push_back(candidates[i]);

            f(candidates, temp, target - candidates[i], i+1);

            //backtrack
            temp.pop_back();
        }
    }
};