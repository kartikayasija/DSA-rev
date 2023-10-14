class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp(nums.size(), -11);

        f(nums, temp, 0);

        return result;
    }

    void f(vector<int>& nums, vector<int>& temp, int idx){

        //base
        if(idx == nums.size()){
            result.push_back(temp);
            return;
        }


        //rec
        for(int i=0; i<temp.size(); i++){
            if(temp[i] != -11){
                continue;
            }

            temp[i] = nums[idx];
            f(nums, temp, idx+1);
            
            temp[i] = -11;
        }
    }
};