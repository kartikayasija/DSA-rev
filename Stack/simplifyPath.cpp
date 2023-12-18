class Solution {
public:
    string simplifyPath(string path) {
        string curr = "";
        stack<string> stk;
        for(char &ch: path+"/") {
            if(ch == '/') {
                if(curr == "..") {
                    if(!stk.empty()) stk.pop();
                }
                //we dont want to push empty or "." in stack
                else if(curr != "" && curr != ".") {
                    stk.push(curr);
                }

                curr = "";
            } else {
                curr += ch;
            }
        }

        string result = "";
        while(!stk.empty()) {
            result = "/" + stk.top() + result;
            stk.pop();
        }

        return result.size() != 0 ? result : "/";
    }
};