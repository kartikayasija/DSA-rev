class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) {
            return nums[0];
        }
        vector<int> mem1(n+1, -1);
        vector<int> mem2(n+1, -1);
        return max(f(0, n-1, nums, mem1), f(1, n, nums, mem2));
    }

    int f(int idx, int n, vector<int> &nums, vector<int> &mem){
        //base
        if(idx>=n){
            return 0;
        }

        if(mem[idx] != -1){
            return mem[idx];
        }

        //rec
        int a1 = nums[idx] + f(idx+2, n, nums, mem);
        int a2 = f(idx+1, n, nums, mem);

        mem[idx] = max(a1, a2);

        return mem[idx];
    }
};

/*
    run house robber 1 two times
    position 0 and n can not come together
    so first run from 0 to n-1
    then 1 to n
    return max of twp
*/