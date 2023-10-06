class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        pair<int,int> p = {n,n};

        f(p, "");

        return result;
    }

    void f(pair<int,int> &p, string str){

        if(p.first==0 and p.second==0){
            result.push_back(str);
            return;
        }


        //rec
        if(p.first == p.second){
            p.first--;
            f(p, str+"(");

            //backtrack
            p.first++;
        } else{
            if(p.first > 0){
                p.first--;
                f(p, str+"(");
                p.first++;
            }

            p.second--;
            f(p, str+")");
            p.second++;
        }
    }
};