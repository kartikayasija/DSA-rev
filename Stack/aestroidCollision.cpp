class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;

        for(int x: asteroids) {  
            while(!stk.empty() and isCollison(x, stk.top())) {
                int maximum = maxi(stk.top(), x);

                //if maxi is again -ve then pop
                if(maximum < 0) {
                    stk.pop();
                } 

                //for equal case
                else if(maximum == 0) {
                    stk.pop();
                    x = 0;
                    break;
                }

                //if positive then break the loop (bcz collision cannot happen)
                else {
                    x = 0;
                    break;
                }
            }

            //dont push for same val case AND positive insertion case
            if(x != 0) stk.push(x);
        }

        vector<int> ans;
        while(!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }


    int maxi (int &a, int &b) {
        //set 0 for equal case, because asteroids[i] != 0
        if(a == -b) return 0;
        if(abs(a) > abs(b)) {
            return a;
        }
        return b;
    }
    
    //will return true if collision is possible
    bool isCollison(int &newElement, int &prev) {
        //is only possible if the newElement is negative, and prev is positive
        if(newElement<0 and prev>0) return true;
        return false;
    }
};