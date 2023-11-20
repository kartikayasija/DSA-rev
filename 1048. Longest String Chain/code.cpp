class Solution {
public:
    static bool sortHelper(string& a, string& b) {
        return a.size() < b.size();
    }

    int longestStrChain(vector<string>& nums) {
        vector<vector<int>> memo (nums.size()+1, vector<int>(nums.size()+1, -1));
        sort(nums.begin(), nums.end(), sortHelper);
        return f(nums, 0, -1, memo);
    }

    int f(vector<string>& nums, int idx, int prevIdx, vector<vector<int>>&memo) {
        //base
        if(idx == nums.size()) {
            return 0;
        }

        //memo
        if(memo[idx][prevIdx+1] != -1) {
            return memo[idx][prevIdx+1];
        }

        //rec
        int notTake = f(nums, idx+1, prevIdx, memo);

        bool condition = prevIdx==-1 or compare(nums[idx],nums[prevIdx]);
        
        int take = condition ? 1+f(nums, idx+1, idx, memo) : 0;

        return memo[idx][prevIdx+1] = max(take, notTake);
    }

    bool compare (string& a, string& b) {
        if(a.size() != b.size()+1) return false;

        int first=0, second=0;

        while(first != a.size()){
            if(a[first] == b[second]) {
                first++;
                second++;
            } else {
                first++;
            }
        }

        if(first == a.size() and second==b.size()) {
            return true;
        }

        return false;
    }
};