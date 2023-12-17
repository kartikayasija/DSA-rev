class Solution {
public:

    /*idea is to find a smaller and a greater value for
    any element of the array before that */    
    bool find132pattern(vector<int>& nums) {
        stack<pair<int, int>> stk;
        int minVal = nums[0];

        for(int &x: nums) {
            while(!stk.empty() && x>=stk.top().first){
                stk.pop();
            }

            //value on top is definitely greater than newVal
            //means greater val found, now compare minVal

            if(!stk.empty() && x > stk.top().second) {
                return true;
            }

            /*update after pushing, as we are storing minVal, 
            before that val in pair*/
            stk.push({x, minVal});
            minVal = min(minVal, x);
        }

        return false;
    }
};