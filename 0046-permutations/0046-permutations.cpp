class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        /*
            initialise it with -11 because -10 <= nums[i] <=10
        */ 

        vector<int> temp(nums.size(), -11); 
        f(nums, 0, temp);
        return result;
    }

    void f(vector<int>& nums, int idx, vector<int> &temp){

        //base
        if(idx==nums.size()){
            result.push_back(temp);
            return;
        }


        //rec
        for(int i=0; i<nums.size(); i++){
            if(temp[i] != -11){
                continue;
            }
            temp[i] = nums[idx]; 
            f(nums, idx+1, temp);
            temp[i] = -11;
        }
    }
};
