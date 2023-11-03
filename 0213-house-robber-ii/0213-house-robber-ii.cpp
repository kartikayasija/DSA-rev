class Solution {
public:
// recursive function to give max of an array not picking adjacent elements

    int maxRob(vector<int>& nums, int end , int n , vector<int>& dp ){
        if(n == end) return nums[end]; // we we'll reach n == end only when we were previously at n+2, we'll never reach here from n+1, so we dont need to worry about skipping it or not , if we reach here means it WILL get picked
        if( n < end ) return 0; // when n = 1 and we picked then we'll call for n-2 and that is -1  so in that case well return 0
        if( dp[n] != -1 ) return dp[n];

        int pick = nums[n] + maxRob(nums,end, n-2, dp);  // since we are picking that element we'll add that element (nums[n] ) and call for n-2  because we have to skip 1 element
        int notPick = 0 + maxRob(nums,end, n-1, dp); // here we are not picking that element ( that's why adding 0 ) and call for n-1 cause we don't need to skip this time since we are not picking the current element

        return dp[n] = max(pick, notPick); // store in dp and return max


    }

    int rob(vector<int>& nums) {
        
        int n = nums.size();

        if( n == 1 ) return nums[0];

        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);

        int case1 = maxRob(nums,0, n-2, dp1); // in case 1 we are passing the nums array from 0 to n-2 ( excluding one from last but including the 0th element )
        int case2 = maxRob(nums,1, n-1, dp2);  // in case 1 we are passing the nums array from 0 to n-1 (till last, but excluding the 0th element)

        return max(case1, case2); // we'll return max of case1 and case2
    }
};