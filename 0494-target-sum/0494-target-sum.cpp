class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return f(nums, 0, target);
    }

    int f(vector<int>& nums, int idx, int target) {

        //base
        if (idx == nums.size()) {
            if (target == 0) {
                return 1;
            }

            return 0;
        }


        //rec
        int a1 = f(nums, idx+1, target-nums[idx]);
        int a2 = f(nums, idx+1, target+nums[idx]);

        return a1+a2;
    }
};