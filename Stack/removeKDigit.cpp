class Solution {
public:

    //first remove decreasing order.
    //now string left will be in increasing order
    //remove from last in this case
    string removeKdigits(string num, int k) {
        stack<char> stk;    

        //removing decreasing order
        for(auto &ch: num) {
            while(k>0 && !stk.empty() && stk.top() > ch) {
                k--;
                stk.pop();
            }

            stk.push(ch);
        }

        //now stk is in increasing order,
        //remove from last (means from top)

        while(k>0 && !stk.empty()) {
            stk.pop();
            k--;
        }    

        string result = "";
        while(!stk.empty()) {
            result += stk.top();
            stk.pop();
        }    
        reverse(result.begin(), result.end());
        //remove starting zeroes
        while (result[0] == '0') result.erase(0 , 1);
        
        //check if result is empty, then make it 0
        if(result.size() == 0) result = "0";

        return result;
    }
};