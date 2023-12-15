class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp = {
            { ']', '[' },
            { '}', '{' },
            { ')', '(' }
        };

        stack<char> stack;

        for(char ch: s) {
            if(mp.find(ch) != mp.end()) {
                if(stack.empty() or stack.top() != mp[ch]) {
                    return false;
                }
                stack.pop();
            } else {
                stack.push(ch);
            }
        }
        
        return stack.empty();
    }
};