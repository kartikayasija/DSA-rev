class Solution {
public:

    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        f(n, k, 1, temp);

        return result;
    }

    void f(int n, int k, int idx, vector<int> &temp){

        if(idx==n+1){
            if(temp.size()==k){
                result.push_back(temp);
            }
            return;
        }
        

        //rec
        f(n, k, idx+1, temp);

        temp.push_back(idx);
        f(n, k, idx+1, temp);
        temp.pop_back();
    }
};