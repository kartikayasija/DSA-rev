class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x: nums){
            sum += x;
        }
        vector<vector<int>> memo(nums.size()+1, vector<int> (sum, -1));

        return f(nums, 0, 0, sum, memo);
    }

    bool f(vector<int>& nums, int idx, int leftSum, int rightSum, vector<vector<int>> &memo) {

        //base
        if(idx==nums.size()){
            if(leftSum == rightSum){
                return true;
            }
            return false;
        }

        //memo
        if(memo[idx][leftSum] != -1){
            return memo[idx][leftSum];
        }

        //rec
        int considered;
        if(nums[idx] <= rightSum){
            considered = f(nums, idx+1, leftSum+nums[idx], rightSum-nums[idx], memo);
        }

        int notConsidered = f(nums, idx+1, leftSum, rightSum, memo);

        return memo[idx][leftSum] = considered or notConsidered;
    }
};