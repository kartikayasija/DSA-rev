class Solution {
public:
    string decodeString(string s) {
        try{
            stack<string> stk;

            for(auto &ch: s) {
                if(ch != ']') {
                    stk.push(string(1, ch));
                    continue;
                }
                
                //extract the inner string
                string res = "";
                while(stk.top() != "[") {
                    res = stk.top() + res;
                    stk.pop();
                }   

                //pop "["
                stk.pop();

                //extract digit (can be 34 as '3', '4' in stack) thats why string
                string digit = "";
                while(!stk.empty() and isdigit(stk.top()[0])) {
                    digit = stk.top() + digit;
                    stk.pop();
                }

                string newString = "";
                for (int i = 0; i < stoi(digit); ++i) {
                    newString += res;
                }
                stk.push(newString);
            }

            string result;
            while(!stk.empty()) {
                result = stk.top() + result;
                stk.pop();
            }
            return result;

        } catch (const exception& e) {
            cout << "Exception caught: " << e.what() <<endl;
            return e.what();
        }
    }
};