class Solution {
public:

    vector<int> result;
    vector<int> lexicalOrder(int n) {
        string temp;
        f(temp, n, 0);

        return result;
    }

    void f(string temp, int &n, int idx){

        /* 
            Can be further optimised
            no need to count in every call as it is fixed;
            memoise it, or make a global variable, set its value from main
        */
        if(idx==countDigits(n)){
            return;
        }

        //rec
        for(int i=0; i<=9; i++){
            if(i==0 and temp.size()==0){
                continue;
            }
            int number = stoi(temp+to_string(i));
            if(number>n){
                continue;
            }
            
            result.push_back(number); //print before backtracking
            f(temp+to_string(i), n, idx+1);
        }
    }

    //helpers
    int countDigits(int number) {
        string numStr = to_string(number);
        return numStr.size();
    }
};