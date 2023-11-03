class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> mem(nums.size()+1, -1);
        return f(0, nums, mem);
    }

    int f(int idx, vector<int> &nums, vector<int> &mem){
        //base
        if(idx>=nums.size()){
            return 0;
        }

        if(mem[idx] != -1){
            return mem[idx];
        }

        //rec
        int a1 = nums[idx] + f(idx+2, nums, mem);
        int a2 = f(idx+1, nums, mem);

        mem[idx] = max(a1, a2);

        return mem[idx];
    }
};