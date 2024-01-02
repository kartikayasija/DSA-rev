class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack< pair<int, int> > stk;

        for(int i=0; i<temperatures.size(); i++) {

            /*if newElement is greater than top, 
            then find difference of their index and 
            change position in array */
            while(!stk.empty() and temperatures[i]>stk.top().first) {
                auto pair = stk.top();
                stk.pop();
                result[pair.second] = i - pair.second; 
            }
            stk.push({temperatures[i], i});
        }

        return result;
    }
};