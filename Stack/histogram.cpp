class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stk; //pair to store height and index
        int maxArea = INT_MIN;

        for(int i=0; i<heights.size(); i++) {
            int start = i;
            //if any smaller element comes, pop all the previous elements
            //keep it increasing
            while(!stk.empty() && stk.top().first > heights[i]) {
                auto pair = stk.top();
                int area = pair.first * (i - pair.second);
                maxArea = max(area, maxArea);
                stk.pop();

                //to extend backward
                start = pair.second;
            }   
            stk.push( {heights[i], start} );
        }

        //extend all remaining elements in stack and find area
        while(!stk.empty()) {
            int width = heights.size() - stk.top().second;
            int area = stk.top().first * width;
            maxArea = max(area, maxArea);
            stk.pop();
        }

        return maxArea;
    }
};

// https://youtu.be/zx5Sw9130L0?feature=shared