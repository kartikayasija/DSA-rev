class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        int j = 0;
        stack <int> stk;

        while(i != popped.size()) {
            if(!stk.empty() && popped[i] == stk.top()){
                stk.pop();
                i++;
            }
            else{
                if(j==pushed.size()){
                    return false;
                }
                stk.push(pushed[j]);
                j++;
            }
        }

        return stk.empty();
    }
};