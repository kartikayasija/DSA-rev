class Solution {
public:
    int climbStairs(int n) {
        vector<int> mem(n+1, -1);
        return f(n,mem);
    }

    int f(int n, vector<int> &mem){

        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(mem[n]==-1){
            int rec_ways = f(n-1, mem) + f(n-2, mem);
            mem[n]=rec_ways;
        }

        
        return mem[n];
    }
};

/*
    https://leetcode.com/problems/climbing-stairs/description/  

    expectation ->
    to calculate ground to top

    faith ->
    rec will calculate from ground to n-1 and n-2
    because only 2 steps
    for k steps, run a loop n-1, n-2, .... , n-k

    total ways -> 
    ways-to-(n-1) x 1 + ways-to-(n-2) x 2

    because dono se ek hi way hai



    mem vector for dp
*/