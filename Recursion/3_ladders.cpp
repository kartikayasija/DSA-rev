/*

Ladder Problem
--------------------------------------------------
Total no. of ways to reach on a top of ladder

let us suppose max jump is 3,
	then to reach top i.e. f(n),
we have three ways, f(n-1) + f(n-2) + f(n-3)
if, max jump is k,
	then f(n-1) + f(n-2)+ .....f(n-k)

to calculate f(n-1)
---------------------------------------------------

*/

#include <iostream>
using namespace std;

int f(int n,int k){
	//base case
	if(n==0) {
		return 1;
	}
	if(n<0) {
		return 0; 
	}

	//recursive
	int ans=0;
	for(int i=1; i<=k; i++) {
		ans+=f(n-i,k);
	}

	return ans;
}

int main() {
	int height_of_latter = 4;
	int max_steps = 3;

	int a = f(height_of_latter,max_steps);
	cout<<a<<endl;
}

/* 
                4
            /   |   \
           3    2    1
         / | \  |\   |
        2  1  0 1 0  0
       /\  |    |
      1  0 0    0
      |
      0

*/