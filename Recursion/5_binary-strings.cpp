/*
Count Binary Strings(0,1) of length N, no consecutive 1
---------------------------------------------------------------------------------------------
there are two case for this
0 at last -->
_ _ _ _ 0  If we have 0 at last, we can simply call same function for (n-1)
because we have fixed 0 at last

1 at last -->
_ _ _ _ _ 1  To deal with this case, it is necessary to put 0 before 1 bcz 1,1 not allowed
_ _ _ _ 0 1  Now we can run same function for n-2 after fixing 0 and 1.

f(n) = f(n-1) + f(n-2)
----------------------------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int f(int n){

	//base
	if(n<=0){
		return 1;  // if length is 0, means no string, it is also considered as valid binary string
	}
	if(n==1){
		return 2;  //two options if length is one, 1 or 0
	}

	return f(n-1) + f(n-2);
}

int main(){
	int ways = f(2);
	cout<<ways<<endl;
}