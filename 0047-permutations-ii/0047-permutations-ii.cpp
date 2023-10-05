class Solution {
public:
    vector<vector<int>> result;
    unordered_map<int,int> map;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(int x: nums){
            map[x]++;
        }
        vector<int> temp;
        f(nums, temp, 0);
        return result;
    }

    void f(vector<int>& nums, vector<int> &temp, int idx){

        //base
        if(idx==nums.size()){
            result.push_back(temp);
            return;
        }
        
        //rec
        for(auto &x: map){
            if(x.second>0){
                x.second--;
                temp.push_back(x.first);
                f(nums, temp, idx+1);

                //backtrack
                temp.pop_back();
                x.second++;
            }
        }
    }
};

/*

    - ek map me freq count liya
    - us map pe hover krke unique numbers liye
    - jb koi nya number lenge, to freq decrease kro

    - fr back track ke time vps increase krdo

*/
