class Solution {
public:
    int findTheWinner(int n, int k) {

        /* 
            +1 is the hacky fix as, it is starting from 1
            the soln involves mod operation, so have to index it
            from 0.
        */

        return f(n, k) + 1;
    }

    int f(int n, int k){
        //base
        if(n==1){
            return 0;
        }

        //rec
        int rec_ans = f(n-1, k);
        int ans = (rec_ans + k) % n;

        return ans;
    }
};

/*
    https://youtu.be/dzYq5VEMZIg
*/