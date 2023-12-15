class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stack;

        for(string s: operations) {
            if(s == "+") {
                int first = stack.top();
                stack.pop();
                int newVal = first + stack.top();
                stack.push(first);
                stack.push(newVal);
            }
            else if(s == "D") {
                int prev = stack.top();
                stack.push(prev*2);
            }
            else if(s == "C") {
                stack.pop();
            }
            else {
                stack.push(stoi(s));
            }
        }


        int sum = 0;
        while(!stack.empty()) {
            sum += stack.top();
            stack.pop();
        }

        return sum;
    }
};