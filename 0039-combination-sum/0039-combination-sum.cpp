class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        f(candidates, {}, target, 0, 0);

        return result;
    }

    void f(vector<int>& candidates, vector<int> temp, int target, int sum, int idx){
        if(sum == target){
            result.push_back(temp);
            return;
        }

        //rec
        for(int i=idx; i<candidates.size(); i++){
            if(candidates[i]+sum > target){
                continue;
            }

            sum = sum+candidates[i];
            temp.push_back(candidates[i]);
            f(candidates, temp, target, sum, i);

            //backtrack
            temp.pop_back();
            sum = sum-candidates[i];
        }
    }
};